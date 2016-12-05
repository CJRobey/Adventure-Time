#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

class Monster {
  private:
    string name;	//name of monster
    int attack;		//attack value of monster
    int health;		//health value of monster
    int escape;		//chance the player has of escaping a fight with the monster

  public:
    //Monster();
    Monster(int health, int attack, int x, string Name);	//constructor for creating a monster
    int getAttack();	//returns the attack value of a monster
    int getHealth();	//returns the health value of a monster
    int getName();	//returns the name of a monster
    int getEscape();	//returns an integer which represents the percent chance the user has of successfully running away from the monster
    void decHealth(int attackPower);	//decrements health of monster based on attack value from the player
    int ptak(int currHealth);	//returns the amount of damage done from the monster on the player
};

Monster::Monster(int health, int attack, int x, string name)	//monsters will always be created by the program with four input arguments
{
	this->health=health;
	this->attack=attack;
	this->name=name;
	this->escape=escape;

}

int Monster::getAttack(){
  return attack;
}

int Monster::getHealth(){
  return this->health;
}

int Monster::getEscape(){
  return escape;
}

void Monster::decHealth(int attackPower){
	this->health-=attackPower;
}


//The monster will either hit for its full amount or will fail to hit at all.
int Monster::ptak(int currHealth){
 int canAttack = rand() % (5);	//random amount of damage done by the monster to the player
 if(canAttack==0) {
	cout<< this->name <<": Oh no! I missed! How is that possible!?" << endl;
	return 0;
 }
 else{
  cout<<"Your current health is " << (currHealth-attack) << " because ";
	return attack;
 }
}
