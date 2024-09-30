#include "Map.h"
#include "Game.h"
#include "Entity.h"

#define RED "\033[41m"     /* Red */
#define GREEN "\033[42m"   /* Green */
#define BLUE "\033[44m"    /* Blue */
#define MAGENTA "\033[45m" /* Magenta */
#define CYAN "\033[46m"    /* Cyan */
#define RESET "\033[0m"

Map::Map(){}

Map::Map(int players_num, int size){
    m_mapArr[players_num][size] = {};
}
int Map::countColors(int player, string color){
int count = 0;
    for (int i = 0; i < 50; i++){
        if (m_mapArr[player][i] == color){
            count++;
        }
    }
    return count;
}
// setter for position on map given the value and which player and then the index for their lane
void Map::setMapPos(string value, int playerID, int index){
    m_mapArr[playerID][index] = value;
}

// getter for position on map given which player and then the index for their lane
string Map::getMapPos(int playerID, int index){
    return m_mapArr[playerID][index];
}

void Map::initializeMap(){

bool valid_count = false;
    // variables to hold random numbers
    int rand_num1, rand_num2;
do{
    for (int i = 0; i < 50; i++){
        /* generate secret number between 1 and 10: */
        rand_num1 = rand() % 50 + 1;
        rand_num2 = rand() % 50 + 1;

        // These conditions roughly set probability for red, green, and blue tiles to roughly 1/3ish
        // STUDENTS: You must alter these to get correct ratios of the tiles that you need
        // Remember, the map is ALWAYS randomized at the start of a new game!!!!
        if ((rand_num1 <= 13)&&(i != 0)&&(getMapPos(0,i-1) != RED)){
            // Keep in mind, I told the compiler that writing the word RED represents the string "\033[41m"
            m_mapArr[0][i] = RED;
        }
        else if ((rand_num1 <= 25)&&(i!= 0)&&(getMapPos(0,i-1) != GREEN)){
            // Keep in mind, I told the compiler that writing the word GREEN represents the string "\033[42m"
            m_mapArr[0][i] = GREEN;
        }
        else{
            // Keep in mind, I told the compiler that writing the word GREEN represents the string "\033[44m"
            m_mapArr[0][i] = BLUE;
        }

        // This part populates the other lane for the second player
        if ((rand_num2 <= 13)&&(i != 0)&&(getMapPos(1,i-1) !=RED )){
            m_mapArr[1][i] = RED;
        }
        else if ((rand_num2 <= 25)&&(i != 0)&&(getMapPos(1,i-1) != GREEN)){
            m_mapArr[1][i] = GREEN;
        }
        else{
            m_mapArr[1][i] = BLUE;
        }
    if((countColors(0,GREEN) >= 3) && (countColors(0,RED) >= 4) && (countColors(1,GREEN) >= 3) && countColors(1,RED) >= 4){
        valid_count = true;
    }
    }}while(valid_count == false);

}



