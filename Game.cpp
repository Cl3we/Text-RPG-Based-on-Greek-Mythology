#include "Game.h"
#include "Map.h"
#include <iomanip>
#include <iostream>
#include <vector>
#include <fstream>
#define RED "\033[41m"     /* Red */
#define GREEN "\033[42m"   /* Green */
#define BLUE "\033[44m"    /* Blue */
#define MAGENTA "\033[45m" /* Magenta */
#define CYAN "\033[46m"    /* Cyan */
#define RESET "\033[0m"


using namespace std;

int split(string input_string, char separator, string arr[], const int ARR_SIZE);



Game::Game(){
_num_players = 2;
_num_enemies = 2;
}
Game::Game(vector <Entity> players, vector <Entity> enemies, int num_players, int num_enemies){
if(num_players <= 2){
    _num_players = num_players;
}
else{
    _num_players = 2;
}
if(num_enemies <= 2){
    _num_enemies = num_enemies;
}
else{
    _num_enemies = 2;
}
for (int i = 0; i < _num_players; i++){
    _players[i] = players[i];
}
for (int i = 0; i < _num_enemies; i++){
    _enemies_list[i] = enemies[i];
}


}
int Game::getNumPlayers(){
    return _num_players;
}
int Game::getNumEnemies(){
    return _num_enemies;
}
void Game::setPlayersList(vector <Entity> players, int num_players){
    int array_size = 0;
    if(num_players <= 2){
        array_size = num_players;
    }
    else{
        array_size = 2;
    }
    for(int i = 0; i < array_size; i++){
        _players[i] = players[i];
    }
    _num_players = array_size;
}
void Game::setEnemiesList(vector <Entity> enemies, int num_enemies){
    int arraysize = 0;
    if(num_enemies <= 2){
        arraysize = num_enemies;
    }
    else{
        arraysize = 2;
    }
    for (int i = 0; i < arraysize; i++){
        _enemies_list[i] = enemies[i];
    }
    _num_enemies = arraysize;
}
bool Game::setPlayer(int index, Entity new_player){
if ((index < _num_players)&&(index>=0)){
    _players[index] = new_player;
    return true;
}
else{
    return false;
}
}
Entity Game::getPlayer(string name){
for (int i = 0; i < _num_players; i++){
    if(_players[i].getName() == name){
        return _players[i];
    }
}
return Entity();
}
bool Game::setEnemy(int index, Entity new_enemy){
    if ((index < _num_enemies)&&(index >= 0)){
    _enemies_list[index] = new_enemy;
    return true;
}
else{
    return false;
}
}
Entity Game::getEnemy(string name){
for (int i = 0; i < _num_enemies; i++){
    if(_enemies_list[i].getName() == name){
        return _enemies_list[i];
    }
}
return Entity();
}
int Game::findPlayer(string name){
for (int i = 0; i < _num_players; i++){
if(name == _players[i].getName()){
    return i;
}
}
return -1;
}
int Game::findPlayerInArray(string name, Entity pc[], int array_size){
for (int i = 0; i < array_size; i++){
if(name == pc[i].getName()){
    return i;
}
}
return -1;
}
int Game::findEnemy(string name){
for (int i = 0; i < _num_enemies; i++){
    if(name == _enemies_list[i].getName()){
        return i;
    }
}
return -1;
}
int Game::findEnemyInArray(string name, Entity mob[], int array_size ){
for (int i = 0; i < array_size; i++){
    if(name == mob[i].getName()){
        return i;
    }
}
return -1;
}
void Game::printAllStats(){
for(int i = 0; i < _num_players; i++){
    cout << _players[i].getName() << "'s stats:" << endl;
   _players[i].printStats();
    cout << "----------------------------------------------" << endl;
}
for(int i = 0; i < _num_enemies; i++){
    cout << _enemies_list[i].getName() << "'s stats:" << endl;
   _enemies_list[i].printStats();
    cout << "----------------------------------------------" << endl;
}
}
void Game::setNumPlayers(int num_players){
_num_players = num_players;
}
void Game::Menu5(){ // edits enemy stats
bool exit5 = false;
string input;
           
int enemies = _num_enemies;
for (int i = 0; i < enemies; i++){
    _enemies_list[i].printStats();
}
while(exit5 == false){
    cout << "which enemy's stats do you want to edit?: " << endl;
    getline(cin, input);
    int index = findEnemy(input);
    if (index == -1){
        cout << "Please select a valid character" << endl;
        continue;
    }
    else{
        cout << "The selected character is: " << endl;
        _enemies_list[index].getName();
    }
    cout << "Editing enemy " << _enemies_list[index].getName() << "'s stats:" << endl;
    cout << "1. Edit hp" << endl;
    cout << "2. Edit gold" << endl;
    cout << "3. Edit condition" << endl;
    getline(cin, input);
    if(input == "1"){
        bool valid1 = false;
        while (valid1 == false){
        cout << "Enter the new value" << endl;
        getline(cin, input);
        if(validateDouble(input)){
            if(stod(input) >= 0){
            _enemies_list[index].setHP(stod(input));
            valid1 = true;
            exit5 = true;
            }
            else{
                cout << "please enter a valid value" << endl;
                continue;
            }
        }
        else{
            cout << "please enter a valid value" << endl;
            continue;
        }
        }
    }
    else if(input == "2"){
        bool valid2 = false;
        while (valid2 == false){
        cout << "Enter the new value" << endl;
        getline(cin, input);
        if(validateDouble(input)){
            if (stoi(input) >= 0){
            _enemies_list[index].setGold(stoi(input));
            valid2 = true;
            exit5 = true;
            }
            else{
                cout << "please enter a valid value" << endl;
                continue;
            }
        }
    else if(input == "3"){
        bool valid3 = false;
        while (valid3 == false){
            cout << "enter the new value" << endl;
            getline(cin,input);
            {
                if (input == "H" || input == "P" || input == "D"){
                    _enemies_list[index].setCondition(input[0]);
                    valid3 = true;
                    exit5 = true;

                }
                else{
                    cout << "please enter a valid value" << endl;
                    continue;
                }
            }
        }

    }
        else{
            cout << "please enter a valid value" << endl;
            continue;
        }
        }


    }
    else if(input == "3"){
        bool valid3 = false;
        while (valid3 == false){
            cout << "enter the new value" << endl;
            getline(cin,input);
            {
                if (input == "H" || input == "P" || input == "D"){
                    _enemies_list[index].setCondition(input[0]);
                    valid3 = true;
                    exit5 = true;


                }
                else{
                    cout << "please enter a valid value" << endl;
                    continue;
                }
            }
        }


    }
    else{


    }}}
void Game::Menu4(){ // edits player stats
bool exit4 = false;
string input;
            
int players = _num_players;
for (int i = 0; i < players; i++){
    _players[i].printStats();
}
while(exit4 == false){
    cout << "which player's stats do you want to edit?: " << endl;
    getline(cin, input);
    int index = findPlayer(input);
    if (index == -1){
        cout << "Please select a valid character" << endl;
        continue;
    }
    else{
        cout << "The selected character is: " << endl;
        _players[index].getName();
    }
    cout << "Editing player " << _players[index].getName() << "'s stats:" << endl;
    cout << "1. Edit hp" << endl;
    cout << "2. Edit gold" << endl;
    cout << "3. Edit condition" << endl;
    getline(cin, input);
    if(input == "1"){
        bool valid1 = false;
        while (valid1 == false){
        cout << "Enter the new value" << endl;
        getline(cin, input);
        if(validateDouble(input)){
            if(stod(input) >= 0){
            _players[index].setHP(stod(input));
            valid1 = true;
            exit4 = true;
            }
            else{
                cout << "please enter a valid value" << endl;
                continue;
            }
        }
        else{
            cout << "please enter a valid value" << endl;
            continue;
        }
        }
    }
    else if(input == "2"){
        bool valid2 = false;
        while (valid2 == false){
        cout << "Enter the new value" << endl;
        getline(cin, input);
        if(validateDouble(input)){
            if (stoi(input) >= 0){
            _players[index].setGold(stoi(input));
            valid2 = true;
            exit4 = true;
            }
            else{
                cout << "please enter a valid value" << endl;
                continue;
            }
        }
        else{
            cout << "please enter a valid value" << endl;
            continue;
        }
        }

    }
    else if(input == "3"){
        bool valid3 = false;
        while (valid3 == false){
            cout << "enter the new value" << endl;
            getline(cin,input);
            {
                if (input == "H" || input == "P" || input == "D"){
                    _players[index].setCondition(input[0]);
                    valid3 = true;
                    exit4 = true;

                }
                else{
                    cout << "please enter a valid value" << endl;
                    continue;
                }
            }
        }

    }
    else{

    }}}

int findEnemyInArray(string name,Entity mob[], int array_size ){
for (int i = 0; i < array_size; i++){
    if(name == mob[i].getName()){
        return i;
    }
}
return -1;
}
int findPlayerInArray(string name, Entity pc[], int array_size){
for (int i = 0; i < array_size; i++){
if(name == pc[i].getName()){
    return i;
}
}
return -1;
}

bool Game::loadCharacters(string filename, vector <Entity> characters, const int CHARACTERS_SIZE){
bool input_bool;
ifstream file_in(filename);
if (!file_in.is_open()){
    return false;
}
string input;
getline(file_in,input);
for (int i = 0; i < CHARACTERS_SIZE ; i++){
    if(file_in.eof()){
        break;
    }
    getline(file_in,input,'|');
    characters[i].setName(input);
    getline(file_in,input,'|');
    characters[i].setType(input[0]);
    getline(file_in,input,'|');
    characters[i].setHP(stod(input));
    getline(file_in,input,'|');
    characters[i].setStamina(stoi(input));
    getline(file_in, input, '|');
    characters[i].setDef(stoi(input));
    getline(file_in, input,'|');
    characters[i].setCondition(input[0]);
    getline(file_in, input,'|');
    if(input == "False"){
        input_bool = false;
    }
    else{
        input_bool = true;
    }
    characters[i].setAdvantage(input_bool);
    getline(file_in, input,'|');
    characters[i].setWeakness(input[0]);
    getline(file_in, input, '|');
    characters[i].setGold(stoi(input));
    getline(file_in, input,'|');
    characters[i].setInventory(input);
    getline(file_in, input,'|');
    characters[i].setQuantities(input);
    getline(file_in, input);
    characters[i].setUltimate(input);

    
    
}
return true;
}
/*
this function finds the initiative at the start
then based on who goes first will 
*/
void Game::combatMenu(string player_name, char type){

bool combat_active = true;
int player_die = 0;
int enemy_die = 0;
int player_init = 0;
int enemy_init = 0;
string input;
int player_index = findPlayer(player_name);
Entity current_enemy;
//int enemy_index = findEnemy(enemy_name);
if(type == 'I'){
do{
int enemy_index = rand()%7+1;
current_enemy = _enemies_list[enemy_index];}
while(current_enemy.getType() != 'I');
}
else{
int boss_index = 4;
current_enemy = _bosses_list[boss_index];
}

cout << "You have encountered a(n) " << current_enemy.getName() << endl;
_players[player_index].printStats();

cout << current_enemy.getWeapon()._name << endl;
current_enemy.printStats();
if (current_enemy.getAdvantage() == _players[player_index].getAdvantage()){
    while(player_init == enemy_init){
        player_die = rand() % 6+1;
        enemy_die = rand() % 6+1;
        if (player_die == enemy_die){
            continue;
        }
        else if(player_die > enemy_die){
            player_init = 1;
        }
        else{
            enemy_init = 1;
        }
    }
}
else if(current_enemy.getAdvantage() > _players[player_index].getAdvantage()){
    enemy_init = 1;
}
else{
    player_init = 1;
}
int turn_count = 1;
int hit_roll;
int armor = 6;
double damage;
int index;
while (combat_active == true){
if (turn_count %2 == player_init){
    cout << "Player " << player_index +1 << " it is your turn" << endl;
    cout << "1. attack" << endl;
    cout << "2. use item" << endl;
    cout << "3. swap equipment" << endl;
    cout << "4. flee" << endl;
    getline(cin,input);
    if (input == "1"){
        cout << "You attacked!" << endl;
        hit_roll = rand() % 20 +1;
        if (hit_roll < armor){
            cout << "your attack missed!" << endl;
        }
        else{
            cout << "Your attack hit!" << endl;
            damage = _players[player_index].CalculateDamage(_players[player_index], current_enemy);
            cout << "damage calculated" << endl;
            current_enemy.TakeEnemyDamge(damage);
            cout << "You dealt " << damage << " damage" << endl;
        }
    }
    else if (input == "2"){
        //will use a consumable
        cout << "Which item will you use?" << endl;
        getline(cin, input);
        index = _players[player_index].findPotion(input);
        if(index == -1){
            cout << "You do not have this item" << endl;
            continue;
        }
        else{
            _players[player_index].usePotion(index);
        }
    }
    else if (input == "3"){
        cout << "which item will you equip?" << endl;
        cout << "1. weapons" << endl;
        cout << "2. shield" << endl;
        cout << "3. return" << endl;
        getline(cin, input);
        if (input == "1"){
            cout << "please enter weapon name" << endl;
            getline(cin, input);
            int weapon_index = _players[player_index].findEquipment(input);
            if (weapon_index == -1){
                cout << "you do not have this item" << endl;
                continue;
            }
            else{
                vector <Equipment> equiplist = _players[player_index].getEquipment();
                _players[player_index].setWeapon(equiplist[weapon_index]);
            }
        }
        else if(input == "2"){
            cout << "please enter shield name" << endl;
            getline(cin, input);
            int shield_index = _players[player_index].findEquipment(input);
            if (shield_index == -1){
                cout << "you do not have this item" << endl;
                continue;
            }
            else{
                vector <Equipment> equiplist = _players[player_index].getEquipment();
                _players[player_index].SetShield(equiplist[shield_index]);
            }
        }
        else if (input == "3"){
            continue;
        }
        else{
            cout << "invalid input" << endl;
            continue;
        }
    }
    else if (input == "4"){
        cout << "As you run away, the " << current_enemy.getName() << " lands one final blow" << endl;
        damage = current_enemy.CalculateDamage(current_enemy,_players[player_index]);
        cout << "damage calculated" << endl;
        _players[player_index].TakePlayerDamage(damage);
        cout << "You took " << damage << " damage" << endl;
        combat_active = false;
        return;

    }
    else{
        cout << "invalid input" << endl;
        continue;
    }}
else{
    cout << current_enemy.getName() << " Attacks!" << endl;
    hit_roll = rand() %20 +1;
    if (hit_roll > armor){
        cout << "The enemy hit!" << endl;
        damage = current_enemy.CalculateDamage(current_enemy,_players[player_index]);
        cout << "damage calculated" << endl;
        _players[player_index].TakePlayerDamage(damage);
        cout << "You took " << damage << " damage" << endl;
    }
    else{
        cout << "The enemy missed!" << endl;
    }
    
}
cout << "Player health: " << _players[player_index].getHP() << endl;
cout << "Enemy health: " << current_enemy.getHP() << endl;
turn_count++;
if ((current_enemy.getHP() <= 0) || (_players[player_index].getHP() <= 0)){
    combat_active = false;
}}
if(_players[player_index].getHP() > 0){
    cout << "You won!" << endl;
    cout << "You got: ";
    cout << current_enemy.getWeapon()._name << ", and " << current_enemy.getSpecificPotion(0)._name << endl;
    _players[player_index].addToEquipment(current_enemy.getWeapon());
    _players[player_index].addToPotions(current_enemy.getSpecificPotion(0));
}


}

Potion Game::getPotion(int index){
    return _allpotions[index];
}
Equipment Game::getEquip(int index){
    return _allequip[index];
}


   bool Game::loadPlayers(){
    bool input_bool;
    string filename = "players_full.txt";
    int CHARACTERS_SIZE = 4;
    ifstream file_in(filename);
    if (!file_in.is_open()){
        return false;
    }
    string input;
    getline(file_in,input);
    Entity character;
    for (int i = 0; i < CHARACTERS_SIZE ; i++){
        if(file_in.eof()){
            break;
        }
        getline(file_in,input,'|');
        _player_list[i].setName(input);
        cout << _player_list[i].getName() << endl;
        getline(file_in,input,'|');
        _player_list[i].setType(input[0]);
        getline(file_in,input,'|');
        _player_list[i].setHP(stod(input));
        getline(file_in,input,'|');
        _player_list[i].setStamina(stoi(input));
        getline(file_in, input, '|');
        _player_list[i].setDef(stoi(input));
        getline(file_in, input,'|');
        _player_list[i].setCondition(input[0]);
        getline(file_in, input,'|');
        if(input == "False"){
            input_bool = false;
        }
        else{
            input_bool = true;
        }
        _player_list[i].setAdvantage(input_bool);
        getline(file_in, input,'|');
        _player_list[i].setWeakness(input[0]);
        getline(file_in, input, '|');
        _player_list[i].setGold(stoi(input));
        getline(file_in, input,'|');
        string list = input;
        _player_list[i].setInventory(input);
        getline(file_in, input,'|');
        string quan = input;
        _player_list[i].setQuantities(input);
        getline(file_in, input);
        _player_list[i].setUltimate(input);
        string inven[2];
        string quantities[2];
        int index;
        split(list, ',', inven , 2 );
        split(quan, ',', quantities, 2);
        int num_potions;
        if(_player_list[i].getType() == 'E' ){
            num_potions = 1;
        }
        else{
            num_potions= stoi(quantities[0]);
        }
        for (int j = 0; j < num_potions; j++){
            index = findPotion(inven[0]);
            cout << "found the potion" << endl;
            _player_list[i].addToPotions(_allpotions[index+1]);
        }
        index = findEquipment(inven[1]);
        cout << _player_list[i].getName()<< endl;
        if(_allequip[index]._type == 'D'){
        _player_list[i].setWeapon(_allequip[index]);
        }
        else{
        _player_list[i].SetShield(_allequip[index]);
        }
        cout << "-weapon is: " << _player_list[i].getWeapon()._name << endl;
        cout << "------------------------------------------" << endl;
    }
    return true;
    }
    
    bool Game::loadEnemies(){
    bool input_bool;
    string filename = "enemies_full.txt";
    int CHARACTERS_SIZE = 7;
    ifstream file_in(filename);
    Entity character;
    if (!file_in.is_open()){
        return false;
    }
    string input;
    getline(file_in,input);
    for (int i = 0; i < CHARACTERS_SIZE ; i++){
        if(file_in.eof()){
            break;
        }
        getline(file_in,input,'|');
        _enemies_list[i].setName(input);
        getline(file_in,input,'|');
        _enemies_list[i].setType(input[0]);
        getline(file_in,input,'|');
        _enemies_list[i].setHP(stod(input));
        getline(file_in,input,'|');
        _enemies_list[i].setStamina(stoi(input));
        getline(file_in, input, '|');
        _enemies_list[i].setDef(stoi(input));
        getline(file_in, input,'|');
        _enemies_list[i].setCondition(input[0]);
        getline(file_in, input,'|');
        if(input == "False"){
            input_bool = false;
        }
        else{
            input_bool = true;
        }
        _enemies_list[i].setAdvantage(input_bool);
        getline(file_in, input,'|');
        _enemies_list[i].setWeakness(input[0]);
        getline(file_in, input, '|');
        _enemies_list[i].setGold(stoi(input));
        getline(file_in, input,'|');
        _enemies_list[i].setInventory(input);
        string list = input;
        getline(file_in, input,'|');
        _enemies_list[i].setQuantities(input);
        string quan = input;
        getline(file_in, input);
        _enemies_list[i].setUltimate(input);
        int index;
        string inven[2];
        string quantities[2];
        split(list, ',', inven , 2 );
        split(quan, ',', quantities, 2);
        int num_potions;
        if(_enemies_list[i].getType() == 'E' ){
            num_potions = 1;
        }
        else{
            num_potions= stoi(quantities[0]);
        }
        for (int j = 0; j < num_potions; j++){
            index = findPotion(inven[0]);
            _enemies_list[i].addToPotions(_allpotions[index+1]);
        }
        index = findEquipment(inven[1]);
        cout << inven[1] << endl;
        _enemies_list[i].setWeapon(_allequip[index]);
        cout << _enemies_list[i].getWeapon()._name << endl;
    }
    return true;
    }
    
    
    bool Game::loadBosses(){
    bool input_bool;
    string filename = "bosses_full.txt";
    int CHARACTERS_SIZE = 3;
    ifstream file_in(filename);
    if (!file_in.is_open()){
        return false;
    }
    string input;
    getline(file_in,input);
    Entity character;
    for (int i = 0; i < CHARACTERS_SIZE ; i++){
        if(file_in.eof()){
            break;
        }
        getline(file_in,input,'|');
        _bosses_list[i].setName(input);
        getline(file_in,input,'|');
        _bosses_list[i].setType(input[0]);
        getline(file_in,input,'|');
        _bosses_list[i].setHP(stod(input));
        getline(file_in,input,'|');
        _bosses_list[i].setStamina(stoi(input));
        getline(file_in, input, '|');
        _bosses_list[i].setDef(stoi(input));
        getline(file_in, input,'|');
        _bosses_list[i].setCondition(input[0]);
        getline(file_in, input,'|');
        if(input == "False"){
            input_bool = false;
        }
        else{
            input_bool = true;
        }
        _bosses_list[i].setAdvantage(input_bool);
        getline(file_in, input,'|');
        _bosses_list[i].setWeakness(input[0]);
        getline(file_in, input, '|');
        _bosses_list[i].setGold(stoi(input));
        getline(file_in, input,'|');
        _bosses_list[i].setInventory(input);
        string list = input;
        getline(file_in, input,'|');
        _bosses_list[i].setQuantities(input);
        string quan = input;
        getline(file_in, input);
        _bosses_list[i].setUltimate(input);
        string inven[2];
        string quantities[2];
        int index;
        split(list, ',', inven , 2 );
        split(quan, ',', quantities, 2);
        int num_potions;
        if(_player_list[i].getType() == 'E' ){
            num_potions = 1;
        }
        else{
            num_potions= stoi(quantities[0]);
        }
        for (int j = 0; j < num_potions; j++){
            index = findPotion(inven[0]);
            cout << "found the potion" << endl;
            _player_list[j].addToPotions(_allpotions[index+1]);
        }
        index = findEquipment(inven[1]);
        _bosses_list[i].setWeapon(_allequip[index]);
    }
    return true;
    }
    
    

void Game::CharacterSelect(){
    string input;
    int num_pcs = 4;
    for(int i = 0; i < num_pcs; i++ ){
        cout << "Player " << i+1 << endl;
        cout << "Here is a list of players you can select from:" << endl;
        for (int k= 0; k < num_pcs; k++){
            _player_list[k].printStats();
            cout << "----------------------------------------------" << endl;
        }
        bool valid_choice = false;
        while (valid_choice == false){
        cout << "Select your character: " << endl;
        getline(cin, input);
        int index = findPlayerInArray(input, _player_list,num_pcs);
        if (index == -1){
            cout << "Invalid Selection! Select from the list" << endl;
        }
        else{
            valid_choice = true;
            cout << "The selected character is: " << endl;
            cout << _player_list[index].getName() << endl;
            _players[i] = _player_list[index];
           
            num_pcs--;
            for (int j = index; j < num_pcs; j++ ){
                if (j >= num_pcs){
                    break;
                }
                _player_list[j] = _player_list[j+1];
            }
            
            }
        }  
        }
}
/*rolls a die
if the result is higher than remaining stamina do as far as stamina
otherwise go as far as dice roll
subtract distance travelled from stamina
then does a check for calamities and impliments them
*/
bool Game::progressCharacter( int player_id, Map map){
int die_roll;
int i;
if (_players[player_id].getShortcut() == false){
die_roll = rand()%6 + 1;
if (_players[player_id].getStamina()  <= 0){
    cout << "You must rest before you can continue your journey" << endl;
    return false;
}
if(_players[player_id].getStamina() <= die_roll){
    die_roll = _players[player_id].getStamina();
}
}
else{
    die_roll = 4;
}

for(i = 0; i < die_roll; i++){
    _players[player_id].setPosition(_players[player_id].getPosition()+1);
    if((map.getMapPos(player_id,_players[player_id].getPosition()) == GREEN) || (map.getMapPos(player_id,_players[player_id].getPosition()) == RED)) {
        break;
    }
}
cout << "You have moved forward " << i << " spaces" << endl;
if(_players[player_id].getShortcut() == false){
_players[player_id].setStamina(_players[player_id].getStamina()-i);
cout << "Your remaining stamina is " << _players[player_id].getStamina() << endl;
}
return true;
}



bool Game::LoadItems(){
    string input;
    ifstream file_in("items.txt");
    int num_equip = 17;
    int num_potions = 9;
    if (!file_in.is_open()){
        return false;
    }
    cout << "opened file" << endl;
    for (int i = 0; i < num_equip; i++){
        getline(file_in, input, '|');
        _allequip[i]._name = input;
        cout << _allequip[i]._name << endl;
        getline(file_in, input, '|');
        _allequip[i]._description = input;
        getline(file_in, input, '|');
        _allequip[i]._type = input[0];
        getline(file_in, input, '|');
        if(_allequip[i]._type == 'D'){
        _allequip[i]._damage = stoi(input);
        _allequip[i]._defense = 0;
        }
        else{
        _allequip[i]._damage = 1;
        _allequip[i]._defense = stoi(input);
        }
        getline(file_in, input, '|');
        _allequip[i]._element = input[0];
        getline(file_in, input);
        _allequip[i]._price = stoi(input);
    }
    cout << "stored equipment" << endl;
    for (int i = 0; i < num_potions; i++){
        if(file_in.eof()){
            break;
        }
        getline(file_in, input, '|');
        _allpotions[i]._name = input;
        getline(file_in, input, '|');
        _allpotions[i]._description = input;
        getline(file_in, input, '|');
        _allpotions[i]._type = input[0];
        getline(file_in, input, '|');
        _allpotions[i]._effect_value = stoi(input);
        getline(file_in, input, '|');
        getline(file_in, input);
        _allpotions[i]._price = stoi(input);
    }
    cout << "stored potions" << endl;
    return true;
}

void Game::gameMenu(Map map){
string input;
bool game_on = true;
//checks if anyone is dead
bool is_dead = false;
//tracks if someone hit ithica
bool ithica = false;
int j = 0;
int chance;
int mvmt;
int riddle_choice;
while (game_on == true){
int i = j%2;
    bool turn_over = false;
    while (turn_over == false){
    //prints out the map at the start of each turn
    for(int i = 0; i < 50; i++){
        if(_players[0].getPosition() == i){
            cout << map.getMapPos(0,i) << "1" << " " << RESET; 
        }
        else{
            cout << map.getMapPos(0,i) << " " << " " << RESET; 
        }
        
    }

    cout << endl;

 for(int i = 0; i < 50; i++){

        if(_players[1].getPosition() == i){
            cout << map.getMapPos(1,i) << "2" << " " << RESET; 
        }
        else{
            cout << map.getMapPos(1,i) << " " << " " << RESET; 
        }
    }
    cout << endl;
    _players[i].printStats();
    cout << "Player " << i+1 << endl;
    cout << "select an option" << endl;
    cout << "1. display your stats" << endl;
    if(_players[i].getSiren() == false){
        cout << "2. move forward" << endl;
    }
    cout << "3. rest" << endl;
    cout << "5. display inventory" << endl;
    cout << "6. quit" << endl;
    _players[i].setSiren(false);
    getline(cin, input);
    if(input == "1"){
        _players[i].printStats();
        cout << "Weapon: "<< _players[i].getWeapon()._name << endl;
    }
    else if(input == "2"){
        bool moved = progressCharacter( i, map);
        if(_players[i].getPosition() >= 49){
            ithica = true;
            game_on = false;
            cout << "You have reached Ithica!" << endl;
            continue;
        }
        if(map.getMapPos(i,_players[i].getPosition()) == GREEN){//island
        if(moved == true){
            cout << "launched combat" << endl;
            combatMenu(_players[i].getName(),'I');
        }
        if (_players[i].getHP() > 0){
            ItemShop(i);
        }
        }
        else if(map.getMapPos(i,_players[i].getPosition()) == BLUE){ //calamities
            chance = rand()%100 +1;
            if(chance <= (30 - _players[i].getBeacon())){
                cout << "You have been struck by a calamity" << endl;
                chance = rand()%100 +1;
                if (chance <= 45){ //Stormy Seas
                    cout << "With each passing moment, the storm grows fiercer, testing your courage and resolve as you struggle to keep your ship afloat amidst the wrath of Poseidon." <<endl;
                    mvmt = rand() %3 +1;
                    if(_players[i].getPosition() - mvmt < 0){
                        _players[i].setPosition(0);
                        mvmt = 0;
                    }
                    else{
                        _players[i].setPosition(_players[i].getPosition() - mvmt);
                    }
                    cout << "You have moved back " << mvmt << " spaces." << endl;
                    
                }
                else if (chance <= 80){ //plague outbreak
                    cout << "The spread of the plague seems unstoppable, defying your best efforts to contain it and leaving you to confront the harsh reality of your own mortality." << endl;
                    _players[i].setCondition('D');
                    cout << "You are now diseased" << endl;
                }
                else{ //poisonous rats
                    cout << "Much to your dismay, it seems you are not the only one on your ship." << endl;
                    _players[i].setCondition('P');
                    cout << "You are now poisoned" << endl;
                }
            }
        }
        else if(map.getMapPos(i,_players[i].getPosition()) == RED){
            turn_over = true;
            chance = rand() %100 +1;
            if(chance <= 20){ //shortcut
                cout << "Your spirits soar as you're propelled ahead. Ithaca isn't far." << endl;
                _players[i].setShortcut(true);
                progressCharacter(i, map);
                _players[i].setShortcut(false);
            }
            else if (chance <= 40){ //siren's song
                cout << "As the Siren's Song echoes through the air, you sense its magical pull, an otherworldly force that toys with the hearts of those who dare to listen. You stop in your tracks. You cannot move on your next turn only" << endl;
                _players[i].setSiren(true);
            }
            else if (chance <= 60){ //Helio's Beacon
                cout << "As you stand in the brilliance of Helios' Beacon, you feel the warmth of the sun god's favor shining upon you. You feel luckier. Reduce calamity chances by 5%, permanently" << endl;
                _players[i].setBeacon(_players[i].getBeacon() + 5);
            }
            else if (chance <= 80){ //Nymph's Spring
                cout << "In the embrace of the Nymph's Spring, you feel the embrace of nature itself. Your stamina is replenished." << endl;
                _players[i].setStamina(_players[i].getMaxStamina());
            }   
            else{ //Riddle time!!
                riddle_choice = rand() %15 +1;
                cout << _riddles[riddle_choice]._name << endl;
                getline(cin, input);
                if(input == _riddles[riddle_choice]._solution){
                    cout << "You are correct! You feel stronger now..." << endl;
                    _players[i].setDamage(_players[i].getDamage() + 5);
                }
                else{
                    cout << "Wrong answer, you missed your chance" << endl;
                }
            }
            turn_over = true;
        }
        
        turn_over = true;
    }
    else if(input == "3"){
        _players[i].setStamina(_players[i].getMaxStamina());
        turn_over = true;
        
    }
    else if(input == "5"){
        _players[i].printInventory();
        
    }
    else if(input == "6"){
        cout << "ending game" << endl;
        turn_over = true;
        game_on = false;
        return;
    }
    else{
        cout << "please select a valid option" << endl;
    }
    if(_players[i].getCondition() == 'P'){
        cout << "You are poisoned... you lose 5 hp" << endl;
        _players[i].setHP(_players[i].getHP()-5);
    }
    else if(_players[i].getCondition() == 'D'){
        cout << "You are diseased... lose 5 stamina" << endl;
        _players[i].setStamina(_players[i].getStamina()-5);
    }
    if(_players[i].getHP() <= 0){
        is_dead = true;
        cout << "Player " << i+1 << " has fallen..." << endl;
        _players[i].SetWinner(false);
    }
    if(ithica == true){
        game_on = false;
        _players[i].SetWinner(true);
    }
    if(is_dead == true){
        game_on = false;
    }
    j++;
    }
    
    
    } 
    
    }


//take string of inventory and get that name matched to something from the equipment list
int Game::findEquipment(string equip){
    for (int i = 0; i < 17; i++){
        if (equip == _allequip[i]._name){
            return i;
        }
    }
    return -1;
}
int Game::findPotion(string potion){
    for (int i = 0; i < 9; i++){
        if (potion == _allpotions[i]._name){
            return i;
        }
    }
    return -1;
}
//converts list of starting inventory to actualy useful inventory
void Game::convertToInventory(string list,string quan, int i){
//many issues from this because I was trying to pass a member and expecting it to edit the member of the array
string inven[2];
string quantities[2];
int index;
cout << _player_list[i].getName() << endl;
split(list, ',', inven , 2 );
cout << "stored inventory" << endl;
split(quan, ',', quantities, 2);
cout << "stored quantities" << endl;
cout << quantities[0] << endl;
int num_potions;
if(_player_list[i].getType() == 'I' ){
    num_potions = 1;
}
else{
    num_potions= stoi(quantities[0]);
}
for (int j = 0; j < num_potions; j++){
    index = findPotion(inven[0]);
    cout << "found the potion" << endl;
    _player_list[j].addToPotions(_allpotions[index+1]);
}
cout << "potions stored" << endl;
index = findEquipment(inven[1]);
cout << inven[1] << endl;
cout << "found equipemnt" << endl;
cout << "index is " << index << endl;
//enchanted wand and nymph's shield throwing error and not being found, hard coded a fix
//foudn a fix I had the variable value wrong
/*
if(inven[1] == "Enchanted Wand"){
    index = 15;
}
if(inven[1] == "Nymph's Shield"){
    index = 16;
}
*/
Equipment starting_item = _allequip[index];
cout << starting_item._name << endl;
if(starting_item._type == 'd'){
_player_list[i].setWeapon(starting_item);
cout << "@@@@@" << _player_list[i].getWeapon()._name << endl;
}
else{
_player_list[i].SetShield(starting_item);
cout << "@@@@@" << _player_list[i].getShield()._name << endl;
}
}

int split(string input_string, char separator, string arr[], const int ARR_SIZE){
    int input_length = input_string.length();
    int j = 0;
    for (int i = 0; i<input_length; i++){
        
        if ((input_string[i] == separator)){
            j++;
            continue;
        }
        if(j >= ARR_SIZE){
            return -1;
        }
        arr[j] += input_string[i];

    }
    if (input_string == ""){
        return 0;
    }
    else{
        return j+1;
    }
}

void Game::ItemShop(int player_index){
    cout << "Player " << player_index +1 << endl;
    bool shop_active = true;
    string input;
    int index;
    int price;
    while(shop_active == true){
        cout << "Would you like to sell or buy?" << endl;
        cout << "1. Sell" << endl;
        cout << "2. Buy" << endl;
        cout << "3. Exit" << endl;
        getline(cin,input);
        if(input == "1"){
            _players[player_index].SellItems();
        }
        else if(input == "2"){
            Potion available_potions[3];
            Equipment available_equipment[3];
            PrintStoreMenu(available_potions, available_equipment);
            cout << "Which item would you like?" << endl;
            getline(cin, input);
            index = findEquipment(input);
            if(index == -1){
                index = findPotion(input);
                if(index == -1){
                    cout << "That is not in our listed items" << endl;
                }
                else{
                    price = _allpotions[index]._price;
                    if(price > _players[player_index].getGold()){
                        cout << "You cannot afford that" << endl;
                        continue;
                    }
                    cout << "Buying: " << _allpotions[index]._name << endl;
                    _players[player_index].addToPotions(_allpotions[index]);
                    _players[player_index].setGold(_players[player_index].getGold() - price);
                }
            }
            else{
                price = _allequip[index]._price;
                if(price == 0){
                    cout << "You cannot purchase this item" << endl;
                    continue;
                }
                if(price > _players[player_index].getGold()){
                    cout << "You cannot afford this item." << endl;
                    continue;
                }
                cout << "Buying " << _allequip[index]._name << endl;
                _players[player_index].addToEquipment(_allequip[index]);
                _players[player_index].setGold(_players[player_index].getGold() - price);
            }
        }
        else if(input == "3"){
            cout << "Exiting shop.." << endl;
            break;
        }
        else{
            cout << "Invalid input. Please enter either 1, 2, or 3" << endl;
            continue;
        }
    }
}
void Game::PrintStoreMenu(Potion available_potions[], Equipment available_equipment[]){
    int potion_size = 3;
    int equip_size = 3;
    int i;
    bool valid_item;
    for (int j = 0; j < equip_size; j++){
        valid_item = false;
        while (valid_item == false){
            i = rand() % 17;
        if(_allequip[i]._price == 0){
            continue;
            }
        else{
            valid_item = true;
        }
        }
        cout << _allequip[i]._name << ": " << _allequip[i]._description << endl;
        cout << "Element: " << _allequip[i]._element << endl;
        if(_allequip[i]._type == 'D'){
            cout << "Damage: " << _allequip[i]._damage << endl;
        }
        else{
            cout << "Defense: " <<_allequip[i]._defense << endl;
        }
        cout << "Price: " << _allequip[i]._price << " gold" << endl;
        cout << "----------------------------------------------" << endl;
        available_equipment[j] = _allequip[i];
    }
    for (int j = 0; j < potion_size; j++){
        i = rand() % 9;
        cout << _allpotions[i]._name << ": " << _allpotions[i]._description << endl;
        cout << "Price: " << _allpotions[i]._price << " gold" << endl;
        cout << "----------------------------------------------" << endl;
        available_potions[j] = _allpotions[i];
    }
}

void Game::PrintEnd(){
    ofstream file_out("results.txt");
    string total_print;
    int equip_size;
    int potion_size;
    for(int i = 0; i < 2; i++){
    equip_size = _players[i].getEquipment().size();
    potion_size = _players[i].getPotions().size();
    file_out << "Player "<< i+1 << ": "<< _players[i].getName()  << endl;
    if(_players[i].getWinner() == true){
        file_out << "You win!" << endl;
    }
    file_out << "Gold: " << _players[i].getGold() << endl;
    file_out << "HP remaining: ";
    if (_players[i].getHP() < 0){
        _players[i].setHP(0);
    }
    file_out << _players[i].getHP() << endl;
    file_out << "Stamina: " << _players[i].getStamina() << endl;
    
    if(_players[i].getWeapon()._name != ""){
        file_out << _players[i].getWeapon()._name <<": " << _players[i].getWeapon()._description << endl;
    }
    if(_players[i].getShield()._name != ""){
        file_out <<_players[i].getShield()._name << ": "<< _players[i].getShield()._description << endl;
    }
   
    for(int j = 0; j < equip_size; j++){
        file_out << _players[i].getEquipment()[j]._name << ": ";
        file_out << _players[i].getEquipment()[j]._description << endl;
    }
    for(int j = 0; j < potion_size; j++){
        file_out << _players[i].getPotions()[j]._name << ": ";
        file_out << _players[i].getPotions()[j]._description << endl;
    }
}
}

void Game::LoadRiddes(){
string input;
ifstream file_in("riddles.txt");
for(int i = 0; i < 15; i++){
    getline(file_in,input,'|');
    _riddles[i]._name = input;
    getline(file_in,input);
    _riddles[i]._solution = input;
}
}
