#include <iostream> 
#include <stdio.h>  
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

#define WORDLEN 5
#define LISTLEN 12947

char clearLine[] = "\33[2K\r";

void yellow(){
		printf("\x1b[30;43m");
}

void green(){
		printf("\x1b[30;42m");
}

void grey(){
		printf("\x1b[0m");
}

string userInput(){

    int ct = 0;
    char c;
    string g(5, ' ');
    
    system("stty raw");

    // backspace -> 127
    // space -> 32
    // enter -> 13

    while(1){

        cout << "|";
        for(int i = 0; i < 5; i++){
            cout << " " << g[i] << " |";
        }

        c = fgetc(stdin);
        cout << clearLine;

        if((int) 'a' <= c && c <= (int) 'z'){
            g[ct] = (char) ((int)c - 32);
            ct += 1;
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

class word{

    public:

        string target;

        word(string wd){
            setWord(wd);
            cout << "target: " << "*****" << "\n";
            counter = 0;
            score = 0;
            exitFlag = 0;
            cout << horiz << "\n";
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

                cout << " " << (char) ::toupper(guess[i]) << " ";
                grey();
                cout << "|";

            }

            cout << "\n" << clearLine << horiz << "\n" << clearLine;
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

    private:

        int counter, score, exitFlag;
        string horiz = "---------------------";

        void setWord(string wd){

            target = wd;

            // return t;
        }



};

int main(){

    cout << "\n      WORD-INAL\n";

    string wd = "ghost";
    string guess;

    word tWord(wd);

    // system("stty raw");

    while(tWord.getExitFlag() == 0){
        guess = userInput();
        tWord.compareWord(guess);
    }

    system("stty cooked");

    return 0;
}