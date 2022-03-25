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

class word{

    public:

        string target;

        word(string wd){
            setWord(wd);
            counter = 0;
            score = 0;
            exitFlag = 0;
            cout << horiz << "\n";
        }
        
        void compareWord(string guess){

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
                cout << "\n\nYou Won!\n\n" << clearLine;
                exitFlag = 1;
            }

            score = 0;

            if(counter == 6){
                cout << "\n\nThe word was \"" << target << "\"\n\n" << clearLine;
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
        }



};

int main(){

    cout << "\tWORD-INAL\n\n";

    string wd = "ghost";
    string guess;

    word tWord(wd);

    // system("stty raw");

    while(tWord.getExitFlag() == 0){
        // cin >> guess;
        guess[0] = fgetc(stdin)
        // cout << "|>>" << guess << "<<|";
        tWord.compareWord(guess);
    }

    system("stty cooked");

    return 0;
}