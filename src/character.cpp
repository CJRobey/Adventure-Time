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

 /*offense is the sum of your level times 5 and the damage
of the weapon equipped */
 int offense;

/*defense probably isn't going to be a thing*/
 int defense;
 int gold;
 void setMaxHealth(int i);

public:
 Character(string name, string type);
 string getName();
 void attack(Monster mon);
 void battle(Monster mon);
 void levelUp();
 void heal(int potionIndex);
 void checkIfDead();
 int getCurrHealth();

};



Character::Character(string name, string type)
{
  this->name = name;
  this->type = type;
  this->level = 1;
  this->maxHealth = 20;
  this->currHealth = maxHealth;
  this->offense = offense + inv.getActiveWeapon().getDamage();


  /*Other things that we need to do here:
  1. initialize the Inventory
  2. determine health, off, def, etc... which will all likely be a product
  of level*/

}

void levelUp() {
  this->level++;
  setMaxHealth(maxHealth+5);

}

void setMaxHealth(int i) {
  this->maxHealth = i;
}




string Character::getName()
{
    return this->name;
};


void Character::battle(Monster mon)
{
  /*combat algorithms need to be determined
  What kind of effect will defense, offense, and weapon type have on damage?
  Will we have accuracy of hits?
  Will we randomize damage within a certain range?*/
  cout << "You have entered into a battle!" << endl;
  cout << "Input a number regarding how you would like to proceed: " << endl;

  while (true) {

  cout << "1. Attack! \n2. Heal \n3. Run..." << endl;

  int userIn;
  cin >> userIn;

  switch(userIn) {
    case 1:
        attack(mon);
        mon.ptak(*currHealth);
    break;
    case 2:
      heal();
      mon.ptak(*currHealth);
    break;
    case 3:
    int v1 = rand() % 100;
      if (v1 < 50) {
      cout << "You managed to run away! " << endl;
      return;
    }
      else {
        cout << "Your character failed to run away." << endl;
        mon.ptak(*currHealth);
        break;
      }
  }
  }
}

int Character::getCurrHealth {
  return this->currHealth;
}

void Character::attack(Monster mon)
{
  int attackPower = rand() % (offense + 1);
  if (attackPower == 0){
    cout << "Your attack was ineffective!\nThe monster laughs at your failure."
    << endl;
  }
  else{
    mon.decHealth(attackPower);
    cout << "The monster was hit for " << attackPower << " points." << endl;
    cout << "The monster now has " mon.getHealh() " health points remainin.";
  }
}

void Character::decrementHealth(int damage){
  this->currHealth = currHealth - damage;
}

bool Character::checkIfDead(){
  if (currHealth <= 0){
    cout << "You've died in battle!\n*GAME OVER*" << endl;
    return true;
  }
  return false;
}

void Character::heal(Potion potion)
{
  Potion potion = inv.getPotion();
  if (potion == NULL) {
    cout << "You don't have a potion, you impotent conglomeration of idiocy." << endl;
    return;
  }
  int potionIndex = potion.recovPoints;

  if (currHealth < maxHealth-potionIndex) {
  this->currHealth += potionIndex;
  cout << "You've been healed by " << potionIndex << " health points." << endl;
}
else {
  this->currHealth = maxHealth;
}


}
