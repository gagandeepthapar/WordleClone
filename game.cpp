#include <iostream> 
#include <stdio.h>  
#include <fstream>
#include <string>
#include <stdlib.h>
#include "word.h"

#define WORDLEN 5
#define LISTLEN 12947

using namespace std;

class game{
    public:

        word target;

        game(){

            srand(time(NULL));
            int r = rand() % LISTLEN;

            FILE *fp = fopen("wordList.txt", "rb");
            fseek(fp, (WORDLEN+1)*r, SEEK_SET);
            
            string wd = "";

            for(int i = 0; i < 5; i++){
                wd = wd + (char) getc(fp);
            }

            target.setWord(wd);

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

};