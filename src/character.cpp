#include <string>
#include <iostream>
#include <cstdlib>
#include "AdventureTime.hxx"


using namespace std;

//class Character
//{
//private:
 //string name;
 //Inventory inv;
 //int level;
 //int currHealth;
 //int maxHealth;

 ///*offense is the sum of your level times 5 and the damage
//of the weapon equipped */
 //int offense;
 //int gold;
 //void setMaxHealth(int i);

//public:
 //Character();
 //Character(string name, Inventory inv);
 //string getName();
 //void attack(Monster mon);
 //bool battle(Monster mon);
 //void levelUp();
 //void heal(int potionIndex);
 //void checkIfDead();
 //int getCurrHealth();
 //int getGold();
 //void decGold(int i);
 //void incGold(int i);
 //void dispCharStats();
 //void setOffense(int damage);


//};

Character::Character(string name, Inventory inv)
{
  this->name = name;
  this->level = 1;
  this->maxHealth = 20;
  this->currHealth = maxHealth;
  this->offense = offense;
  this->gold = 0;
  this->inv = inv;

  /*Other things that we need to do here:
  1. initialize the Inventory
  2. determine health, off, def, etc... which will all likely be a product
  of level*/
}

int Character::getGold() {
  return this->gold;
}

/*This will be used for selling items and obtaining gold*/
void Character::incGold(int i) {
  this->gold = gold + i;
}

/*the following will be used for buying items */
void Character::decGold(int i) {
  this->gold = gold - i;
}

void Character::setOffense(int x) {
  this->offense = offense + x;
}

void Character::levelUp() {
  this->level++;
  setMaxHealth(maxHealth+5);
  incGold(100);

  this->offense = offense + 5;
}

void Character::setMaxHealth(int i) {
  this->maxHealth = i;
}

string Character::getName()
{
    return this->name;
};


bool Character::battle(Monster mon)
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
	int damageAmount;
    int userIn;
    cin >> userIn;

    switch(userIn) {
      /*THIS METHOD IS NOT FINISHED
      Need to account for cases in which the character dies*/


      //choose to fight
      case 1:
        attack(mon);
        if (mon.getHealth() <= 0) {
          cout << "The battle is over." << endl;
          return deadness;
        }
        damageAmount = mon.ptak(currHealth);
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
        damageAmount = mon.ptak(currHealth);
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
      if (v1 < mon.getEscape()) {
        cout << "You managed to run away! " << endl;
        return deadness;
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

int Character::getCurrHealth() {
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
    if (mon.getHealth() <= 0) {
      cout << "Your hit landed for " << attackPower << " damage points and killed the monster!" << endl;
      return;
    }
    cout << "The monster was hit for " << attackPower << " points." << endl;
    cout << "The monster now has " << mon.getHealth() << " health points remainin." << endl;
  }
}

void Character::decHealth(int damage){
  this->currHealth = currHealth - damage;
}

bool Character::checkIfDead(){
  if (currHealth <= 0){
    cout << "You've died in battle!\n*GAME OVER*" << endl;
    return true;
  }
  return false;
}

void Character::heal()
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
