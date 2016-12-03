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
 int getGold();
 void decGold();
 void incGold();

};

void Character(string name, string type)
{
  this->name = name;
  this->type = type;
  this->level = 1;
  this->maxHealth = 20;
  this->currHealth = maxHealth;
  this->offense = offense + inv.getActiveWeapon().getDamage();
  this->gold = 0;

  /*Other things that we need to do here:
  1. initialize the Inventory
  2. determine health, off, def, etc... which will all likely be a product
  of level*/
}

int getGold() {
  return this->gold;
}

/*This will be used for selling items and obtaining gold*/
void incGold(int i) {
  this->gold = gold + i;
}

/*the following will be used for buying items */
void decGold(int i) {
  this->gold = gold - i;
}

void levelUp() {
  this->level++;
  setMaxHealth(maxHealth+5);
  incGold(100);

  this->offense = offense + 5;
}

void setMaxHealth(int i) {
  this->maxHealth = i;
}

string getName()
{
    return this->name;
};


bool battle(Monster mon)
{
  bool deadness = false;
  /*So here's the deal: we are going to return a bool that indicates whether or
  not our character is dead at the end of the battle.*/
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
    /*THIS METHOD IS NOT FINISHED
    Need to account for cases in which the character dies*/

    //choose to fight
    case 1:
      attack(mon);
      if (mon.getHealth <= 0) {
        cout << "The battle is over." << endl;
        return;
      }
      int damageAmount = mon.ptak(currHealth);
      decHealth(damageAmount);
      cout << "You have been hit for " << damageAmount << " points." << endl;
      deadness = checkIfDead();
      if (deadness == true) {
        return deadness;
      }
    break;

    //choose to heal self
    case 2:
      heal();
      int damageAmount = mon.ptak(currHealth);
      decHealth(damageAmount);
      cout << "You have been hit for " << damageAmount << " points." << endl;
      deadness = checkIfDead();
      if (deadness == true) {
        return deadness;
      }
    break;

    //choose to attempt to run
    case 3:
    int v1 = rand() % 100;
    if (v1 < 50) {
      cout << "You managed to run away! " << endl;
      return;
    }
    else {
      cout << "Your character failed to run away." << endl;
      int damageAmount = mon.ptak(currHealth);
      decHealth(damageAmount);
      cout << "You have been hit for " << damageAmount << " points." << endl;
      deadness = checkIfDead();
      if (deadness == true) {
        return deadness;
      }
    break;
    }
  }
  }
}

int getCurrHealth {
  return this->currHealth;
}

void attack(Monster mon)
{
  int attackPower = rand() % (offense + 1);
  if (attackPower == 0){
    cout << "Your attack was ineffective!\nThe monster laughs at your failure."
    << endl;
  }
  else{
    mon.decHealth(attackPower);
    if (mon.getHealth() <= 0) {
      cout << "Your hit landed for " << attackPower << " damage points and killed the monster!" << endl;
      return;
    }
    cout << "The monster was hit for " << attackPower << " points." << endl;
    cout << "The monster now has " mon.getHealh() " health points remainin." << endl;
  }
}

void decHealth(int damage){
  this->currHealth = currHealth - damage;
}

bool checkIfDead(){
  if (currHealth <= 0){
    cout << "You've died in battle!\n*GAME OVER*" << endl;
    return true;
  }
  return false;
}

void Character::heal(Potion potion)
{
  Potion potion = inv.usePotion();
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
  int arbNum = currHealth;
  this->currHealth = maxHealth;
  cout << "You've been healed by " << maxHealth - arbNum << " health points." << endl;
}

}
