#include <string>
#include <iostream>
#include <map>
#include <limits>
#include <cstdlib>
#include "Inventory.cpp"
#include "Monster.cpp"
//#include "AdventureTime.h"


using namespace std;

class Character
{
private:
 string name;
 Inventory inv;
 int level;
 int currHealth;
 int maxHealth;
/*offense is the sum of your level times 5 and the damage
of the weapon equipped */
 int offense;
 int gold;

public:
 Character();
 Character(string name, Inventory &inv);
 string getName();
 void setMaxHealth(int i);
 void attack(Monster &mon);
 int battle(Monster& mon);
 void levelUp();
 void heal();
 bool checkIfDead();
 int getCurrHealth();
 int getGold();
 void decGold(int i);
 void incGold(int i);
 void dispCharStats();
 void incOffense(int damage);
 void decHealth(int i);
 void incHealth(int i);
 map<string, Weapon>* getWepInventory();
 void setInventory();
 Inventory getInv();
 void addInvWeapon(Weapon w);
 int remInvWeapon(string item);
 int addPotionToInv();
 int sellPotionChar();


};

Character::Character() {
  //do nothing... just wait.
}

Character::Character(string name, Inventory &inv)
{
  this->name = name;
  this->level = 1;
  this->maxHealth = 100;
  this->currHealth = maxHealth;
  this->offense = 10;
  this->gold = 0;
  this->inv = inv;
  /*Potion healing will also be determined by the amount of total health points*/
  this->inv.setPotionCost(20);
  this->inv.setPotionHealing(10);

}

void Character::levelUp() {
  this->level++;
  setMaxHealth(maxHealth+50);
  this->currHealth = currHealth + 50;
  //incGold(100);

  /*Potion healing will also be determined by the amount of total health points*/

  //this will raise the potion's cost at stores
  inv.setPotionCost(inv.getPotCost() + 20);
  //this will change its healing ability to 1/2 + 1 of the user's max health
  inv.setPotionHealing(((int) maxHealth * 0.8)+1);

  this->offense = offense + 5;

  cout << "You leveled up!" << endl;
}


int Character::getGold() {
  return this->gold;
}

Inventory Character::getInv() {
  return inv;
}

/*This will be used for selling items and obtaining gold*/
void Character::incGold(int i) {
  this->gold += i;
  cout << "You received " << i << " gold." << endl;
}

/*the following will be used for buying items */
void Character::decGold(int i) {
  this->gold -= i;
}

void Character::incOffense(int x) {
  this->offense = offense + x;
}


void Character::setMaxHealth(int i) {
  this->maxHealth = i;
}

string Character::getName()
{
    return this->name;
};

//@caleb this getWeapon isn't defined look at this
//void Character::gotAWeapon() {
  //this->offense = this->offense + getWeapon();
//}


int Character::battle(Monster &mon)
{

  //this will return an int -> 0 for a win, 1 for a run, 2 for a death
  bool deadness = false;
  cout << "You have entered into a battle!" << endl;
  cout << "Input a number regarding how you would like to proceed: " << endl;

  while (true) {

    cout << "1. Attack! \n2. Heal \n3. Run..." << endl;
	int damageAmount;
    int userIn;

    //You will see the format of the next 5 lines of code throughout this
    //program. It is a wrapper to prevent bad input, specifically for ints.
    int num;
		while(!(cin >> num) || num < 1 || num > 3){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout<<"Invalid input: please choose again"<<endl;
		}
    userIn = num;

    switch(userIn) {
      /*THIS METHOD IS NOT FINISHED
      Need to account for cases in which the character dies*/
      //choose to fight
      case 1:
        attack(mon);
        if (mon.getHealth() <= 0) {
          cout << "Congratulations, you have won the battle." << endl;
          incGold(100);
          levelUp();
          return 0;
        }
        damageAmount = mon.ptak(currHealth);
        decHealth(damageAmount);
        cout << "you have been hit for " << damageAmount << " points." << endl;
        deadness = checkIfDead();
        if (deadness) {
          return 2;
        }
      break;

      //choose to heal self
      case 2:
        heal();
        damageAmount = mon.ptak(currHealth);
        decHealth(damageAmount);
        cout << "You have been hit for " << damageAmount << " points." << endl;
        deadness = checkIfDead();
        if (deadness) {
          return 2;
        }
      break;

      //choose to attempt to run
      case 3:
      if ((rand() % 100) < mon.getEscape()) {
        cout << "You managed to run away! " << endl;
        return 1;
      }
      else {
        cout << "Your character failed to run away." << endl;
        int damageAmount = mon.ptak(currHealth);
        decHealth(damageAmount);
        cout << "You have been hit for " << damageAmount << " points." << endl;
        deadness = checkIfDead();
        if (deadness) {
          return 2;
        }
      break;
      }
    }
  }
}

int Character::getCurrHealth() {
  return this->currHealth;
}

void Character::attack(Monster &mon)
{
  int attackPower = rand() % (offense + 1);
  if (attackPower == 0){
    cout << "Your attack was ineffective!\nThe monster laughs at your failure."
    << endl;
  }
  else{
    mon.decHealth(attackPower);
    if (mon.getHealth() <= 0) {
      cout << "Your hit landed for " << attackPower << " damage points and killed the enemy." << endl;
      return;
    }
    cout << "The monster was hit for " << attackPower << " points." << endl;
    cout << "The monster now has " << mon.getHealth() << " health points remaining." << endl;
  }
}

void Character::decHealth(int damage){
  this->currHealth = currHealth - damage;
}

void Character::incHealth(int damage){
  if (currHealth < maxHealth-damage) {
  this->currHealth += damage;
  cout << "You've been healed by " << damage << " health points." << endl;
  }
  else {
  this->currHealth = maxHealth;
  cout << "You have been restored to maximum health of " << maxHealth << " points." << endl;
  }
}


bool Character::checkIfDead(){
  if (currHealth <= 0){
    cout << "You've died in battle!\n*GAME OVER*" << endl;
    return true;
  }
  return false;
}

int Character::sellPotionChar() {
  return this->inv.sellPotion();
}

void Character::heal()
{
  int recovPoints = inv.usePotion();
  if (recovPoints == 0) {
    cout << "You don't have a potion, you impotent conglomeration of idiocy." << endl;
    return;
  }

  if (currHealth < maxHealth-recovPoints) {
  this->currHealth += recovPoints;
  cout << "You've been healed by " << recovPoints << " health points." << endl;
  }
  else {
    int arbNum = currHealth;
    this->currHealth = maxHealth;
    cout << "You've been healed by " << maxHealth - arbNum << " health points." << endl;
  }

}

void Character::dispCharStats()
{
  cout << "Character name: " << this->name << endl;
  cout << "level: " << this->level << endl;
  cout << "maximum health: " << this->maxHealth << endl;
  cout << "current health: " << this->currHealth << endl;
  cout << "offense: " << this->offense << endl;
  cout << "gold: " << this->gold << endl;
  inv.disInventory();

}

map<string, Weapon>* Character::getWepInventory() {
  return this->inv.getWeaponMap();
}

void Character::addInvWeapon(Weapon w) {
  this->inv.addWeapon(w);
}

int Character::remInvWeapon(string item) {
  return this->inv.drop(item);
}

//this will return the cost of the potion to the Store class
int Character::addPotionToInv() {

  if (inv.getPotCount() > 9) {
    cout << "Your potion inventory is full! You can't buy any more potions." << endl;
    return 0;
  }
  else {
  inv.addPotion();
  return inv.getPotCost();
  }

}
