#include <string>
#include <iostream>
#include <cstdlib>
#include "AdventureTime.h"

using namespace std;

class Character
{
private:
 string name;
 string type;
 Inventory inv;
 int level;
 int currHealth;
 int maxHealth;
 int offense;
 int defense;
 int gold;
 void setMaxHealth(int i);

public:
 Character(string name, string type);
 string getName();
 void attack(Character opponent);
 void heal(int potionIndex);
 void run();
};



Character::Character(string name, string type)
{
  this->name = name;
  this->type = type;
  this->level = 1;

  /*Other things that we need to do here:
  1. initialize the Inventory
  2. determine health, off, def, etc... which will all likely be a product
  of level*/

}




string Character::getName()
{
    return this->name;
};


void Character::battle(Character opponent)
{
  /*combat algorithms need to be determined
  What kind of effect will defense, offense, and weapon type have on damange?
  Will we have accuracy of hits?
  Will we randomize damage within a certain range?*/

  cout << "You have entered into a battle!" << endl;
  cout << "Input a number how you would like to proceed: " << endl;

  while (true));

  cout << "1. Attack! \n2. Heal \n3. Run..." << endl;

  int userIn << cin;

  switch(userIn) {
    case 1:
        attack(opponent);
    break;
    case 2:
      heal(inv.potion);
    break;
    case 3:
      cout << "You ran away! " << endl;
    return;    
  }




}


void Character::attack(Character opponent)
{

}

void Character::heal(Potion potion)
{
  if (currHealth < maxHealth-potionIndex) {
  this->currHealth += potion.recovPoints;
}
else {
  this->currHealth = maxHealth;
}

}


void run();
