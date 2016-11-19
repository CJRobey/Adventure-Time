#include <string>
#include <iostream>
#include <cstdlib>
#include "AdventureTime.h"

using namespace std;


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


void Character::attack(Character opponent)
{
  /*combat algorithms need to be determined
  What kind of effect will defense, offense, and weapon type have on damange?
  Will we have accuracy of hits?
  Will we randomize damage within a certain range?*/

}

void Character::heal(int potionIndex)
{
  if (currHealth < maxHealth-potionIndex) {
  this->currHealth += potionIndex;
}
else {
  this->currHealth = maxHealth;
}

}


void run();
