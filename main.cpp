/**************************************************************************************
* 																					  *
*																					  *
* This Project is done for Tribhuwan University, IOE : Purwanchal Campus, Dharan      *
* By :																				  *
* 1. Sangharsha Dahal : PUR076BEI029												  *
* 2. Samin Gaire : PUR076BEI028														  *
* 3. Mandip Rajak : PUR076BEI019													  *
* 4. Amit Poudel : PUR076BEI003														  *
																					  *
***************************************************************************************/

#include <iostream>
#include "Dictionary.h"

using namespace std;

// Main function
int main() {
  Dictionary dict;
  string w;
  int choice;

  // Home Screen
  do {
	cout<<"\n\n\t********* DICTIONARY *********"<<endl;
    cout << "\n\n\t\t**MAIN MENU**\n";
    cout << "\n\t\t1. Search Word";
    cout << "\n\t\t2. Read Fav";
    cout << "\n\t\t3. Write Fav";
    cout << "\n\t\t4. Read History";
    cout << "\n\t\t5. Assistant Mode";
    cout << "\n\t\t6. Exit";
    cout<<"\n\n\n\t******************************"<<endl;

    cout << "\nEnter your choice (1-6) : ";
    cin >> choice;
    switch (choice) {
    case 1:
      cout << "Enter a word to search: ";
      cin >> w;
      cout<<"\n";
      // calling method to search the word
      dict.findWord(w);
      // writing into history file immediately
      dict.setHistory(w);
      break;
    case 2:
      // calling method to read fav file
      dict.getFav();
      break;
    case 3:
      // if user wants he/she can write a word
      // just searched into fav file
      dict.setFav();
      break;
    case 4:
      // invoking method to read history file
      dict.getHistory();
      break;
    case 5:
      // writing current meaning into ttsData file
      dict.ttsWrite();
      // invoking method to read ttsData file
      dict.ttsRead();
      // clearing TTS data after read
      dict.ttsDataClear();
      break;
    case 6:
      exit(0);
      break;
    default:
      cout << "\n....Invalid Choice....\nTry Again !!!\n";
      exit(0);
      break;
    }
  } while (choice != 6);

  return 0;
}
