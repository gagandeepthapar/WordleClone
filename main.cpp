#include <iostream> 
#include <stdio.h>  
#include <fstream>
#include <string>
#include <stdlib.h>

#include "word.h"
#include "game.h"

using namespace std;
string clearLine = "\33[2K\r";


int main(){

    cout << "\n      WORD-INAL\n";
    game clone;
    clone.playGame();

    // system("stty raw");
    // cout << "p\np\np\n";
    // fgetc(stdin);

    // cout << "\33[1A\r" << clearLine;
    // cout << "\33[1A\r" << clearLine;
    // cout << "\33[1A\r" << clearLine;

    //     cout << "b\nb\nb\n";

    return 0;
}