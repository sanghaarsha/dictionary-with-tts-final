#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Dictionary Class
class Dictionary {
private:
string meaning{};

public:
  // Method to search for a word & display a meaning if found
  // else display not found message
  void findWord(string word) {
    ifstream file("oxford.txt");
    string line;

    // Converting the given input into Title-Cased
    // to match with the word in dictionary file
    if (word[0] >= 97 && word[0] <= 122)
      word[0] -= 32;

    while (getline(file, line)) {

      // storing first word of line in firstWord variable
      // every first word of the dictionary is stored in the variable
      // and matched with user given input till EOF
      stringstream ss{line};
      string firstWord;
      ss >> firstWord;

      if (firstWord == word) {
        
        //wiriting into meaning variable
        meaning = line + "\n";
      }
    }
    
    // line variable is empty if word doesn't match
    // display word not found error
    if (meaning == "") {
      cout << "\nThe word '" << word << "' not found!\nPlease check the spelling and try again.";
    }else{
    	 cout<<meaning<<endl;
    }
  }

  // method to write fav. file
  void setFav() {
    ofstream fav;
    fav.open("fav.txt", ios::app); // ios::app => append mode, adds new line to eof.
    fav << meaning + "\n";
    fav.close();
  }

  // method to write history file
  void setHistory(string word) {
    ofstream historyfile;
    historyfile.open("history.txt", ios::app); // ios::app => append mode
    historyfile << word + "\n";
    historyfile.close();
  }

  // method to read fav file
  void getFav() {
    fstream fav;
    fav.open("fav.txt", ios::in);
    if (!fav) {
      cout << "File not found!!";
    } else {
      string ch;
      while (getline(fav, ch)) {
        cout << ch << "\n";
      }
    }
    fav.close();
  }

  // method to read history file
  void getHistory() {
    fstream history;
    history.open("history.txt", ios::in);
    if (!history) {
      cout << "File not found!!";
    } else {
      string ch;
      while (getline(history, ch)) {
        cout << ch << "\n";
      }
    }
    history.close();
  }
  
  // writing the current data in ttsData.txt file  for 'Festival TTS' to read
  void ttsWrite(){
  	ofstream ttsData;
        ttsData.open("ttsData.txt", ios::app);
        ttsData << meaning + "\n";
        ttsData.close();
  }
  
  // Reading the data in ttsData.txt file 
  // by running the shell command to pipe the data in file 
  // into the festival engine
  // make sure to run 'sudo chmod +x ttsRreader.sh' before running the program
  void ttsRead(){
  	//reading Current word meaning
  	system("./ttsRreader.sh");
  	
  }
  
  //clearing ttsData for next data to be read
  void ttsDataClear(){
  	ofstream ttsData;
	ttsData.open("ttsData.txt", std::ofstream::out | std::ofstream::trunc);
	ttsData.close();
	//clearing the screen
	system("clear");
	}
};

#endif
