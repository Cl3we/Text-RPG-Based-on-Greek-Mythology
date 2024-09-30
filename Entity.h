#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <vector>

using namespace std;


struct Potion{
string _name;
string _description;
char _type;
double _effect_value;
double _price;
};

struct Equipment{
string _name;
string _description;
char _type;
//d damage s shield
char _element;
//(w water, f fire, a air, e earth)
double _damage;
//0 for shields
double _defense;
//0 for weapons
double _price;
};

class Entity{
private:
string _name;
char _type;
double _hp;
int _stamina;
int _def;
char _condition;
bool _advantage;
char _weakness;
int _gold;
int _damage = 0;
Equipment _weapon;
Equipment _shield;
vector <Potion> _potions;
vector <Equipment> _equipment;
string _inventory_list;
string _quantities;
int _position;
string _ultimate;
double _calamity_chance;
int _stamina_max = 150;
bool _winner = false;
int _beacon;
bool _siren = false;
bool _shortcut = true;



public:
Entity();
Entity(string, double, int, char, bool, int, int);
string getName();
double getHP();
char getCondition();
int getGold();
void setName(string name);
void setHP(double);
void setCondition(char);
void setGold(int);
void setType(char);
char getType();
void setDef(int);
int getDef();
void setAdvantage(bool);
bool getAdvantage();
void setStamina(int);
int getStamina();
void setWeakness(char);
char getWeakness();
void setInventory(string);
void setQuantities(string);
void setUltimate(string);
void printStats();
double getCalamityChance();
void swap(int UserChoice);
void drop(int UserChoice);
void usePotion(int Userchoice);
void updateEquipment(int equipIndex, Equipment weapon);
int getPosition();
void setPosition(int);
void TakePlayerDamage(double);
void TakeEnemyDamge(double);
double CalculateDamage(Entity, Entity);
Equipment getWeapon();
string getUltimate();
void addToEquipment(Equipment);
void addToPotions(Potion item);
int getMaxStamina();
void printInventory();
void setWeapon(Equipment);
void SetShield(Equipment);
Equipment getShield();
int findEquipment(string);
vector <Equipment> getEquipment();
int findPotion(string name);
Potion getSpecificPotion(int index);
void SellItems();
void SetWinner(bool);
bool getWinner();
int getBeacon();
void setBeacon(int);
void setSiren(bool);
bool getSiren();
bool getShortcut();
void setShortcut(bool);
void OutputInventory(ofstream);
int getDamage();
vector <Potion> getPotions();
void setDamage(int);
};

#endif