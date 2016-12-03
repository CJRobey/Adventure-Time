#include <string>
#include <iostream>
#include <cstdlib>
#include "AdventureTime.h"

class Monster {
  private:
    string name;
    int attack;
    int health;
    int escape;
    
  public:
    Monster(int health, int attack, int x, string Name);
    int getAttack();
    int getHealth();
    int getName();
    int getEscape();
    void decHealth(int attackPower);
    int ptak(int currHealth);
};

Monster::Monster(int health, int attack, int x, string Name)
{
	this->health=health;
	this->attack=attack;
	this->name=name;
	this->escape=escape;
	
}

int getAttack(){
  return attack;
}

int getHealth(){
  return health;
}

int getEscape(){
  return escape;	
}

void decHealth(int attackPower){
	this->health-=attackPower;
}

int ptak(int currHealth){
 cout<<"Your current health is " << currHeath << " but not for long!" << endl;
 int canAttack = rand() % (5);
 if(canAttack==0) {
	cout<< "Oh no! I missed! How is that possible!?"
	return 0;
 }
 else{
	return attack;
 }
}
