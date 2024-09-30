#include "Game.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#define RED "\033[41m"     /* Red */
#define GREEN "\033[42m"   /* Green */
#define BLUE "\033[44m"    /* Blue */
#define MAGENTA "\033[45m" /* Magenta */
#define CYAN "\033[46m"    /* Cyan */
#define RESET "\033[0m"

bool validateDouble(string input);


int main(){
    Game newgame;
    srand (time(NULL));

    Map starterMap = Map();
    // initialize tiles
    starterMap.initializeMap();

    // demonstrate tiles = these numbers will show up to
    // this top lane corresponds to player 1
    for(int i = 0; i < 50; i++){

        cout << starterMap.getMapPos(0,i) << "1" << " " << RESET; 
    }

    cout << endl;

 for(int i = 0; i < 50; i++){

        cout << starterMap.getMapPos(1,i) << "2" << " " << RESET; 
    }

    // // Use RESET to revert back to the default terminal text color when done
    cout << RESET << endl;
    newgame.LoadItems();
    newgame.loadPlayers();
    newgame.loadEnemies();
    newgame.loadBosses();
    newgame.LoadRiddes();
    cout << "Select your character" << endl;
    newgame.CharacterSelect();
    newgame.ItemShop(0);
    newgame.ItemShop(1);
    newgame.gameMenu(starterMap);
    newgame.PrintEnd();


    return 0;
}


bool validateDouble(string input){
    int length = input.length();
    int j = 0;
    if (length == 0){
        return false;
    }
    for (int i = 0; i < length; i++){
        if ((input[i] == '-')&&(i == 0)&&isdigit(input[i+1])){
            continue;
        }
        if (isdigit(input[i])){
            continue;
        }
        if ((input[i] == '.')&&(i<length-1)){
            continue;
            j++;
            if (j > 1){
                return false;
            }
        }
        return false;
    }
    return true;
}

