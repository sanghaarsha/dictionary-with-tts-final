# A simple dictionary program created using C++ for the Assesment Exam of TU IOE Purwanchal Campus Dharan. 
## By:

 Sangharsha Dahal
 Samin Gaire
 Mandip Rajak
 Amit Poudel

## Details

This program runs in any platform having gcc compiler but to run assistant mode
make sure you are using Linux, and have installed festival TTS.

In Ubuntu/Debian based systems by running:
sudo apt-get install festival festvox-kallpc16k

In arch-based system by running:
pacman -S festival festival-us

Then make sure to go to the code directory and run:
chmod +x ttsRreader.sh

This shell command gives executable permisson to the ttsReader.sh file,
which job is to pipe the text to be read into TTS engine, so this is must.

Now finally you can run the program(if you have gcc installed) by running:
g++ -Wall -std=c++14 main.cpp -o bin && ./bin

## If you have any suggestions you can send pull requests.

