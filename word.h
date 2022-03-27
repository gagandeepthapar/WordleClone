# pragma once

#include <iostream> 
#include <stdio.h>  
#include <fstream>
#include <string>
#include <stdlib.h>

#define WORDLEN 5
#define LISTLEN 12947

using namespace std;

int counter = 0;
int score = 0;
int exitFlag = 0;

string horiz = "|-----------------------------|\n";
string spacer = "|     |     |     |     |     |\n";
string charSpacer = "|     |     |     |     |     |\n";
string clearLine = "\33[2K\r";
void (*colorStyle[WORDLEN])(char);

class word{

    public:
        
        void compareWord(string guess){

            transform(guess.begin(), guess.end(), guess.begin(), ::tolower);

            for(int i = 0; i < WORDLEN; i++){
                if(guess[i] == target[i]){
                    colorStyle[i] = green;
                    score += 1;
                }
                else if(target.find(guess[i]) != string::npos){
                    colorStyle[i] = yellow;
                }
                else{
                    colorStyle[i] = grey;
                }
            }

            cout << "\33[1A\r" << clearLine;
            cout << "\33[1A\r" << clearLine;
            cout << "\33[1A\r" << clearLine;
            cout << "\33[1A\r" << clearLine;
        
            for(int i = 0; i < WORDLEN; i++){
                colorStyle[i](' ');
            }
            grey(' ');
            cout << "\n" << clearLine;

            for(int i = 0; i < WORDLEN; i++){
                colorStyle[i](::toupper(guess[i]));
            }
            grey(' ');
            cout << "\n" << clearLine;

            for(int i = 0; i < WORDLEN; i++){
                colorStyle[i](' ');
            }
            grey(' ');
            cout << "\n" << clearLine;
            cout << horiz << clearLine;

            counter += 1;

            if(score == 5){
                winCon();

            }

            score = 0;

            if(counter == 6){
                loseCon();

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
            
            system("stty raw");

            // backspace -> 127
            // space -> 32
            // enter -> 13
            // esc -> 27

            while(1){

                c = inputAndFormat(g);
                
                if((int) 'a' <= c && c <= (int) 'z'){
                    if(ct < 5){
                        g[ct] = (char) ((int)c - 32);
                        ct += 1;
                    }
                }

                else if(c == 13){
                    if(ct == 5){
                        system("stty cooked");
                        return g;
                    }
                }
                
                else if(c == 127){
                    if(ct > 0){
                        ct -=1;
                        g[ct] = ' ';
                    }
                }

                else if(c == 27){
                    system("stty cooked");
                    exit(0);
                }

                cout << "\33[1A\r" << clearLine;
                cout << "\33[1A\r" << clearLine;
                cout << "\33[1A\r" << clearLine;
                cout << "\33[1A\r" << clearLine;

            }

            return g;

        }

    private:

        string target;

        static void yellow(char c){
                cout << "\x1b[0m" << '|' << "\x1b[30;43m" << "  " << c << "  ";
        }

        static void green(char c){
                cout << "\x1b[0m" << '|' << "\x1b[30;42m" << "  " << c << "  ";
        }

        static void grey(char c){
                cout << "\x1b[0m" << '|' << "\x1b[0m" << "  " << c << "  ";
        }

        char inputAndFormat(string g){
            char c;

            int j = 0;
            for(int i = 3; i < spacer.length(); i += 6){
                charSpacer[i] = g[j];
                j += 1;
            }
            j = 0;

            cout << spacer << clearLine << charSpacer << clearLine << spacer << clearLine << horiz << clearLine;

            c = fgetc(stdin);

            return c;

        }

        void winCon(){
            
            string header(31, ' ');
            string msg = "You Won!";

            header[0] = '|';
            header[30] = '|';

            for(int i = 0; i < msg.length(); i++){
                header[i + header.length()/2 - msg.length()/2] = msg[i];
            }

            cout << header << "\n" << horiz;
            exitFlag = 1;

            return;

        }

        void loseCon(){

            string header(31, ' ');
            transform(target.begin(), target.end(),target.begin(), ::toupper);
            string msg = "The word was " + target;

            header[0] = '|';
            header[30] = '|';

            for(int i = 0; i < msg.length(); i++){
                header[i + header.length()/2 - msg.length()/2] = msg[i];
            }

            cout << header << "\n" << horiz;
            exitFlag = 1;

            return;
        }

};
