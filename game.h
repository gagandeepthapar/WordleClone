#pragma once

#include <iostream> 
#include <stdio.h>  
#include <fstream>
#include <string>
#include <stdlib.h>
#include "word.h"
using namespace std;

#define WORDLEN 5
#define LISTLEN 12947

string header (31, ' ');
string title = "WORD-INAL";

class game{
    public:
        game(){
            
            formatHeader();
            setTarget();

        }

        void playGame(){

            while(target.getExitFlag() == 0){
                guess = target.userInput();
                target.compareWord(guess);
            }

            system("stty cooked");

            return;
            
        }

    private:

        string guess;
        word target;

        void formatHeader(){

            header[0] = '|';
            header[30] = '|';

            for(int i = 0; i < title.length(); i++){
                header[i + header.length()/2 - title.length()/2] = title[i];
            }

            cout << horiz << header << "\n" << horiz;

        }

        void setTarget(){
            
            srand(time(NULL));
            int r = rand() % LISTLEN;

            FILE *fp = fopen("wordList.txt", "rb");
            fseek(fp, (WORDLEN+1)*r, SEEK_SET);
            
            string wd = "";

            for(int i = 0; i < 5; i++){
                wd = wd + (char) getc(fp);
            }

            target.setWord(wd);

            fclose(fp);

        }

};