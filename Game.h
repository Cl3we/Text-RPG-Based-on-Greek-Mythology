#include "Entity.h"
#include "Map.h"


#ifndef GAME_H
#define GAME_H

using namespace std;

bool validateDouble(string input);

struct Riddle{
string _name;
string _solution;
};


class Game{
private:
    int _num_players;
    int _num_enemies;
    Entity _players[2];
    Entity _player_list[4];
    Entity _enemies_list[7];
    Entity _bosses_list[3];
    Potion _allpotions[9];
    Equipment _allequip[17];
    int _player_postition[2][50];
    Riddle _riddles[15];
    
public:
/*General constructor*/
Game();
/*Parameterized contructor*/
Game(vector <Entity>, vector <Entity>, int, int);
/*returns number of players*/
int getNumPlayers();
/*returns number of enemies*/
int getNumEnemies();
/*sets the array of players*/
void setPlayersList(vector <Entity>, int);
/*Sets an array of enamies*/
void setEnemiesList(vector <Entity>, int);
/*sets a player at an index as a specified antity*/
bool setPlayer(int, Entity);
/*returns the entity*/
Entity getPlayer(string);
/*sets an enemy entiry at an index*/
bool setEnemy(int, Entity);
/*returns the enemy*/
Entity getEnemy(string);
/*finds a player in the _players array*/
int findPlayer(string);
/*finds an entity with the name as the string in a specified entity of a certain size*/
int findPlayerInArray(string, Entity[], int);
/*does findplayer for _enemeis*/
int findEnemy(string);
/*does findPlayerInArray for enemies*/
int findEnemyInArray(string, Entity[], int);
/*prints the stats of all players and enemies*/
void printAllStats();
/*stats the number of players*/
void setNumPlayers(int);
/*loads the overall menu
Needs to be rewritten after the one from homework as it covers the wrong things other than the player selecting a character*/
void loadMenu();
/*loads the menu for option 4*/
//will probably get deleted because why would the player need to be able to directly edit stats
void Menu4();
/*Loads the menu for option 5*/
//will probably get deleted because why would the player need to be able to directly edit stats
void Menu5();
/*Loads a list of the characters*/
bool loadCharacters(string filename, vector <Entity>, const int CHARACTERS_SIZE);
/*runs the turn based combat*/
void combatMenu(string player_name, char type);
/*menu running island options after combat*/
void islandMenu();
/*runs the end of the game including outputing stats to a file*/
void endGame();
//returns the entity at an index
Potion getPotion(int);
//returns the equipment at indexs
Equipment getEquip(int);
//loads the player characters;
bool loadPlayers();
//loads the enemies
bool loadEnemies();
//loads epic enounters
bool loadBosses();
//the initial character select menu;
void CharacterSelect();
//moves the selected character forward in the map
bool progressCharacter(int player_id, Map map);
//returns the position on the map
int getPosition();
//the menu the gives the player options
void gameMenu(Map);
//loads the items
bool LoadItems();
//finds an item by it's name and returns it's index
int findEquipment(string equip);
//converts list of starting inventory to actualy useful inventory
void convertToInventory(string list,string, int);
//returns a potions from the potions array
int findPotion(string potion);
//opens the item shop
void ItemShop(int);
//prints the store menu
void PrintStoreMenu(Potion[],Equipment[]);
void PrintEnd();
void LoadRiddes();
};



#endif