#pragma once

#include <iostream> 
#include <stdio.h>  
#include <fstream>
#include <string>
#include <stdlib.h>

#define WORDLEN 5
#define LISTLEN 12947

using namespace std;

class word{

    public:

        string target;

        word(){
            cout << horiz;
        }
        
        void compareWord(string guess){

            cout << clearLine;

            for(int i = 0; i < 5; i++){
                guess[i] = (char) ::tolower(guess[i]);
            }

            cout << "|";
            for(int i = 0; i < 5; i++){

                if(guess[i] == target[i]){
                    green();
                    score += 1;
                }
                else if(target.find(guess[i]) != string::npos){
                    yellow();
                }
                else{
                    grey();
                }

                cout << "  " << (char) ::toupper(guess[i]) << "  ";
                grey();
                cout << "|";

            }

            // cout << ;

            cout << "\n" << spacer << clearLine << horiz << spacer << clearLine;
            counter += 1;

            if(score == 5){
                cout << "\n      You Won!\n\n" << clearLine;
                exitFlag = 1;
            }

            score = 0;

            if(counter == 6){
                cout << " The word was \"" << target << "\"\n\n" << clearLine;
                exitFlag = 1;
            }

        }

        int getExitFlag(){
            return exitFlag;
        }        
        
        void setWord(string wd){

            target = wd;

            // return t;
        }

        string userInput(){

            int ct = 0;
            char c;
            string g(5, ' ');
            
            string spacer = "|     |     |     |     |     |\n";
            system("stty raw");

            // backspace -> 127
            // space -> 32
            // enter -> 13

            while(1){

                cout << spacer << clearLine;
                cout << "|";
                for(int i = 0; i < 5; i++){
                    cout << "  " << g[i] << "  |";
                }

                cout << "\n" << clearLine << spacer;

                c = fgetc(stdin);
                cout << clearLine;
                cout << "\33[1A\r" << clearLine;
                cout << "\33[2A\r" << clearLine;

                if((int) 'a' <= c && c <= (int) 'z'){
                    if(ct < 5){
                        g[ct] = (char) ((int)c - 32);
                        ct += 1;
                    }
                }

                if(c == 13){
                    if(ct == 5){
                        system("stty cooked");
                        return g;
                    }
                }
                
                if(c == 127){
                    if(ct > 0){
                        ct -=1;
                        g[ct] = ' ';
                    }
                }

            }

            return g;

        }

    private:

        int counter = 0;
        int score = 0;
        int exitFlag = 0;

        string horiz = "|-----------------------------|\n";
        string spacer = "|     |     |     |     |     |\n";
        string clearLine = "\33[2K\r";


        void yellow(){
                printf("\x1b[30;43m");
        }

        void green(){
                printf("\x1b[30;42m");
        }

        void grey(){
                printf("\x1b[0m");
        }

};
