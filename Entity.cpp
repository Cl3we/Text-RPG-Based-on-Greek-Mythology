#include "Entity.h"
#include "Game.h"
#include "Map.h"
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

Entity::Entity(){
_name = "";
_hp = 0;
_gold = 0;
_condition = 'H';
_def = 0;
_equipment = {};
_potions = {};
}
Entity::Entity(string name, double hp, int gold, char condition, bool is_enemy , int atk, int def){
_name = name;
if (hp >= 0){
_hp = hp;
}
else{
    _hp = 0;
}
if(gold >= 0){
_gold = gold;
}
else{
    _gold = 0;
}
if ((condition == 'H') || (condition == 'P') || (condition == 'D')){
    _condition = condition;
}
else{
    _condition = 'H';
}

}
string Entity::getName(){
return _name;
}
double Entity::getHP(){
return _hp;
}
char Entity::getCondition(){
return _condition;
}
int Entity::getGold(){
    return _gold;
}

void Entity::setName(string name){
    _name = name;
}
void Entity::setHP(double hp){
if (hp >= 0){
    _hp = hp;
}
else{
    _hp = 0;
}
}
void Entity::setCondition(char condition){
if (condition == 'H' || condition == 'P' || condition == 'D'){
    _condition = condition;
}
else{
    condition = 'H';
}
}
void Entity::setGold(int gold){
    if(gold >= 0){
        _gold = gold;
    }
    else{
        _gold = 0;
    }
    
}

void Entity:: setDef(int def){
    _def = abs(def);
}
int Entity:: getDef(){
    return _def;
}
void Entity::setType(char type){
    _type = type;
}
char Entity::getType(){
    return _type;
}
void Entity::setStamina(int stam){
    _stamina = stam;
}
int Entity::getStamina(){
    return _stamina;
}
void Entity::setAdvantage(bool adv){
    _advantage = adv;
}
bool Entity::getAdvantage(){
    return _advantage;
}
void Entity::setWeakness(char weak){
    _weakness = weak;
}
char Entity::getWeakness(){
    return _weakness;

}
void Entity::setInventory(string inven){
    _inventory_list = inven;
}
void Entity::setQuantities(string quan){
    _quantities = quan;
}
double Entity::getCalamityChance(){
    return _calamity_chance;
}
void Entity::swap(int UserChoice){

}
void Entity::drop(int UserChoice){

}
void Entity::usePotion(int index){
int size = _potions.size();
if(_potions[index]._name == "Lesser Health Potion"){
    _hp = _hp + _potions[index]._effect_value;
}
else if(_potions[index]._name == "Greater Health Potion"){
    _hp = _hp + _potions[index]._effect_value;
}
else if(_potions[index]._name == "Lesser Stamina Potion"){
    _stamina = _stamina + _potions[index]._effect_value;
}
else if(_potions[index]._name == "Greater Stamina Potion"){
    _stamina = _stamina + _potions[index]._effect_value;
}
else if(_potions[index]._name == "Cleansing Potion"){
    _condition = 'H';
}
else if(_potions[index]._name == "Greater Rejuvenation Potion"){
    _hp = _hp + _potions[index]._effect_value;
    _stamina = _stamina + _potions[index]._effect_value;
}
else if(_potions[index]._name == "Lesser Rejuvenation Potion"){
    _hp = _hp + _potions[index]._effect_value;
    _stamina = _stamina + _potions[index]._effect_value;
}
else if(_potions[index]._name == "Minor Strength Potion"){
    _damage = _damage + _potions[index]._effect_value;
}
else if(_potions[index]._name == "Major Strength Potion"){
    _damage = _damage + _potions[index]._effect_value;
}
_potions[index] = _potions[size-1];
_potions.pop_back();

}
void Entity::updateEquipment(int equipIndex, Equipment weapon){

}

void Entity::printStats(){
    cout << _name << "'s stats:" << endl;
    cout << "HP: " << fixed << setprecision(2) << _hp << endl;
    cout << "Condition: " << _condition << endl;
    cout << "Gold: " << _gold << endl;
    cout << "Defense: " << _def << endl;
    cout << "Type: " <<_type << endl;
    cout << "Stamina: " << _stamina << endl;
    cout << "Weakness: " << _weakness << endl;
    
}

int Entity::getPosition(){
    return _position;
}

void Entity::setPosition(int pos){
    _position = pos;
}
void Entity::TakePlayerDamage(double damage){
double health_loss = damage*2.5;
setHP(getHP()-health_loss);
}
void Entity::TakeEnemyDamge(double damage){
double health_loss = damage*3.5;
setHP(getHP()-health_loss);
}
double Entity::CalculateDamage(Entity attacker, Entity defender){
//cannot impliment damage until weapons acutally attatch to these fucks
int attack = attacker.getWeapon()._damage + attacker._damage;
cout << attacker.getWeapon()._name << endl;
int def = defender.getShield()._defense;

cout << attack << endl;
double damage = rand() % attack +1 - def;


if (damage <= 0){
    damage = 1;
}
if (attacker.getWeapon()._element == defender.getWeakness()){
    damage = damage*2;
}
return damage;
}
Equipment Entity::getWeapon(){
    return _weapon;
}

void Entity::setUltimate(string ultimate){
    _ultimate = ultimate;
}
string Entity::getUltimate(){
    return _ultimate;
}

void Entity::addToEquipment(Equipment item){
_equipment.push_back(item);
}
void Entity::addToPotions(Potion item){
_potions.push_back(item);
}
int Entity::getMaxStamina(){
    return _stamina_max;
}
void Entity::printInventory(){
    int equip_size = _equipment.size();
    int potion_size = _potions.size();
    if(_weapon._name != ""){
        cout << _weapon._name <<": " << _weapon._description << endl;
    }
    if(_shield._name != ""){
        cout <<_shield._name << ": "<< _shield._description << endl;
    }
    
    for(int i = 0; i < equip_size; i++){
        cout << _equipment[i]._name << ": ";
        cout << _equipment[i]._description << endl;
    }
    for(int i = 0; i < potion_size; i++){
        cout << _potions[i]._name << ": ";
        cout << _potions[i]._description << endl;
    }
}

void Entity::setWeapon(Equipment weapon){
    _weapon = weapon;
}
void Entity::SetShield(Equipment shield){
    _shield = shield;
}
int Entity::findEquipment(string name){
    int size = _equipment.size();
    for(int i = 0; i < size; i++){
        if(name == _equipment[i]._name){
            return i;
        }
    }
    return -1;
}
int Entity::findPotion(string name){
    int size = _potions.size();
    for(int i = 0; i < size; i++){
        if(name == _potions[i]._name){
            return i;
        }
    }
    return -1;
}
vector <Equipment> Entity::getEquipment(){
    return _equipment;
}
Equipment Entity::getShield(){
    return _shield;
}
Potion Entity::getSpecificPotion(int index){
    return _potions[index];
}


void Entity::SellItems(){
    string input;
    int index;
    int potion_size;
    int equipment_size;
    int price;
    printInventory();
            cout << "Which item would you like to sell?" << endl;
            getline(cin, input);
            index = findEquipment(input);
            if(index == -1){
                index = findPotion(input);
                if(index == -1){
                    cout << "You do not have this item" << endl;
                    return;
                }
                else{
                    potion_size = _potions.size();
                    cout << "Selling " << _potions[index]._name << endl;
                    cout << "You recieved " << _potions[index]._price << " gold." << endl;
                    price = _potions[index]._price;
                    _gold = _gold + price;
                    _potions[index] = _potions[potion_size-1];
                    _potions.pop_back();
                    cout << "You have " << _gold <<" gold." << endl;
                }
            }
            else{
                if(_equipment[index]._price == 0){
                    cout << "You cannot sell epic items" << endl;
                    return;
                }
                equipment_size = _equipment.size();
                cout << "Selling " << _equipment[index]._name << endl;
                cout << "You recieved " << _equipment[index]._price << " gold." << endl;
                price = _equipment[index]._price;
                _gold = _gold + price;
                _equipment[index] = _equipment[equipment_size -1];
                _equipment.pop_back();
                cout << "You have " << _gold << " gold." << endl;
            }
}
void Entity::SetWinner(bool winner){
_winner = winner;
}
int Entity::getBeacon(){
return _beacon;
}
void Entity::setBeacon(int beacon){
    _beacon = beacon;
}
void Entity::setSiren(bool siren){
    _siren = siren;
}
bool Entity::getSiren(){
    return _siren;
}
bool Entity::getShortcut(){
    return _shortcut;
}
void Entity::setShortcut(bool shortcut){
    _shortcut = shortcut;
}
bool Entity::getWinner(){
    return _winner;
}
void Entity::OutputInventory(ofstream file_out){
    int equip_size = _equipment.size();
    int potion_size = _potions.size();
    if(_weapon._name != ""){
        file_out << _weapon._name <<": " << _weapon._description << endl;
    }
    if(_shield._name != ""){
        file_out <<_shield._name << ": "<< _shield._description << endl;
    }
   
    for(int i = 0; i < equip_size; i++){
        file_out << _equipment[i]._name << ": ";
        file_out << _equipment[i]._description << endl;
    }
    for(int i = 0; i < potion_size; i++){
        file_out << _potions[i]._name << ": ";
        file_out << _potions[i]._description << endl;
    }
}
int Entity::getDamage(){
    return _damage;
}
void Entity::setDamage(int damage){
    _damage = damage;
}
vector <Potion> Entity::getPotions(){
    return _potions;
}