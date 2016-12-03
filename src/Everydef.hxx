/* For now, let's try to keep it to one header file for the project, but we can
change this if necessary. */
#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <sstream>

using namespace std;

class Monster {
  private:
    string name;
    int attack;
    int health;
    int escape;

  public:
    Monster(int health, int attack, int x, string name);
    int getAttack();
    int getHealth();
    int getName();
    int getEscape();
    void decHealth(int attackPower);
    int ptak(int currHealth);
};


/*This class will be extended into "weapon," "potion," and possibly a few other
types*/
class Item {

  protected:  //uses protected so that extensions can access these variables
    string type, name;
    int cost,worth;

  public:
    Item();
    Item(string type, int cost, int worth, string name);

    void setName(string name);

    void setCost(int cost);

    string getName();

    string getType();

    int getCost();

    int getWorth();
};

class Weapon  : public Item {

  private:  //damage variable is visible by only the Weapon class
    int damage;

  public:
    Weapon();
    Weapon(int damage);
    void setDamage(int damage);
    int getDamage();

};

//Potion Class is an extension of Item Class
class Potion : public Item {

  private:  //healing variable is visible by only the Weapon class
    int healing;
    int amount;

  public:
    Potion();
    Potion(int healing);
    void setHealing(int healing);
    void setAmount(int amount);
    int getHealing();
	int getAmount();

};



class Inventory {

  private:
    map<string, Weapon> Weapons;
    Potion P;

  public:
    Inventory();
    void disInventory();
    int drop(string itemName);
    void addPotion(int amount);
    void addWeapon(Weapon W);
    int usePotion();
    int getWeapon();
    void setPotionAmount(int amount);
    void setPotionHealing(int healing);
    void setPotionCost(int cost);
    void setPotionName(string name);
    int getPotionAmount();
    int getPotionHealing();

};


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
	 void setMaxHealth(int i);

	public:
	 Character(string name, Inventory inv);
	 string getName();
	 void attack(Monster mon);
	 bool battle(Monster mon);
	 void levelUp();
	 void decHealth(int damage);
	 void heal();
	 bool checkIfDead();
	 int getCurrHealth();
	 int getGold();
	 void decGold(int i);
	 void incGold(int i);
	 void dispCharStats();
	 void setOffense(int damage);
     void gotAWeapon();


};



class Store
{
  private:
	 Weapon wepinventory[];
     Potion potinventory[];

  public:
	Store();
    void openStore(Character charactername, Inventory inventoryname);
    void getWepInventory(Inventory inventoryname);
    void getPotInventory(Inventory inventoryname);
    void getCharInventory(Inventory inventoryname);
    void buy(string itemnumber, int itemtype);
    void sell(Character charactername, Inventory inventoryname, string itemname);
};

/*Store*/

Store::Store(){
}

/*inventory*/
Inventory::Inventory(){};

     void Inventory::disInventory(){
        Weapon iteratedWeapon;
        string name, damage, worth, spaces, cost, healing, amount= "";
        int length,attribute;
        stringstream ss;
        spaces = "                    ";
        cout << endl << "\t|~|~|~|~|~|~|~|~|~|~| INVENTORY |~|~|~|~|~|~|~|~|~|~|" << endl << endl;
        cout << "\tWeapon         Damage    Price     Worth" << endl;
        for(map<string, Weapon>::iterator iter = Weapons.begin(); iter != Weapons.end(); ++iter) {
            iteratedWeapon = Weapons[iter->first];
            name = iteratedWeapon.getName();
            length = name.length();
            cout << "\t" << name << spaces.substr(0,15-length);
            attribute = iteratedWeapon.getDamage();
            ss << attribute;
            damage = ss.str();
            ss.str("");
            length = damage.length();
            cout << damage << spaces.substr(0,10-length);
            attribute = iteratedWeapon.getCost();
            ss << attribute;
            cost = ss.str();
            ss.str("");
            length = cost.length();
            cout << cost << spaces.substr(0,10-length);
            attribute = iteratedWeapon.getWorth();
            ss << attribute;
            worth = ss.str();
            ss.str("");
            cout << worth << endl;
        }
        cout << endl;
        cout << "\tName         Healing   Price     Worth     Amount" << endl;
            name = P.getName();
            //cout << "Name is " << name << endl;
            length = name.length();
            //cout << "Length of name is " << length << endl;
            cout << "\t" << name << spaces.substr(0,15-length);
            attribute = P.getHealing();
            ss << attribute;
            healing = ss.str();
            ss.str("");
            length = healing.length();
            cout << healing << spaces.substr(0,10-length);
            attribute = P.getCost();
            ss << attribute;
            cost = ss.str();
            ss.str("");
            length = cost.length();
            cout << cost << spaces.substr(0,10-length);
            attribute = P.getWorth();
            ss << attribute;
            worth = ss.str();
            ss.str("");
            length = worth.length();
            cout << worth << spaces.substr(0,10-length);
            attribute = P.getAmount();
            ss << attribute;
            amount = ss.str();
            ss.str("");
            cout << amount << endl;
        cout << endl;
        cout << "\t|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|" << endl << endl;
    }

    int Inventory::drop(string itemName) {
        int worth;
        if (Weapons.count(itemName)) {
            worth = Weapons[itemName].getWorth();
            Weapons.erase(itemName);
            cout << itemName << " has been removed." << endl;
        }

        else if (!itemName.compare(P.getName())) {
            if (P.getAmount() > 1) {
                P.setAmount(P.getAmount()-1);
                worth = P.getWorth();
            }
            else {
                cout << "You do not own enough potion!" << endl;
                worth = 0;
            }
        }
        else {
            cout << "You don't own that item!" << endl;
            worth = 0;
        }
        return worth;
    }

    void Inventory::addPotion(int amount) {
        P.setAmount(P.getAmount()+amount);
    }

    void Inventory::addWeapon(Weapon W) {
        string weaponName = W.getName();
        if (Weapons.count(weaponName))
            cout << "You already own that weapon!" << endl;
        else {
            Weapons[weaponName] = W;
            cout << weaponName << " has been added!" << endl;
        }
    }

    int Inventory::usePotion() {
        int healing;
        if(P.getAmount() > 0) {
            P.setAmount(P.getAmount()-1);
            healing = P.getHealing();
        }
        else {
            healing = 0;
            cout << "You do not own enough potion!" << endl;
        }
        return healing;
    }

    int Inventory::getWeapon() {
        Weapon currentWeapon;
        int maxDamage = 0;
        for(map<string, Weapon>::iterator iter = Weapons.begin(); iter != Weapons.end(); ++iter) {
            currentWeapon = Weapons[iter->first];
            if (currentWeapon.getDamage() > maxDamage) {
                maxDamage = currentWeapon.getDamage();
            }

        }
        return maxDamage;
    }

    void Inventory::setPotionHealing(int healing) {P.setHealing(healing);} //set healing value

    void Inventory::setPotionAmount(int amount) {P.setAmount(amount);} //set amount of potions

    void Inventory::setPotionCost(int cost) {P.setCost(cost);}

    void Inventory::setPotionName(string name) {P.setName(name);}

    int Inventory::getPotionAmount() {return P.getAmount();} //returns amount of a specific potion

    int Inventory::getPotionHealing(){return P.getHealing();} //return healing value

/*item*/
    Item::Item(){} //default constructor does not need to initialize anything
    Item::Item(string type, int cost, int worth, string name) { //second constructor
      this->type = type;
      this->cost = cost;
      this->worth = worth;
      this->name = name;
    }

    void Item::setName(string name){this->name = name;} //set name of item

    void Item::setCost(int cost){ //set cost and therefore worth of item
      this->cost = cost;
      this->worth = int(cost*0.6);  //worth is 60% of initial cost
    }

    string Item::getName(){return this->name;}  //return name of item

    string Item::getType(){return this->type;}  //return type of item

    int Item::getCost(){return this->cost;} //return cost of item

    int Item::getWorth(){return this->worth;} //return worth of item


//Weapon Class is an extension of Item Class

    Weapon::Weapon(){ //default constructor must initialize the type of item
      this->type = "Weapon";
    }
    Weapon::Weapon(int damage) {  //second constructor must also initialize type
      this->damage = damage;
      this->type = "Weapon";
    }

    void Weapon::setDamage(int damage) {this->damage = damage;} //set damage of item

    int Weapon::getDamage(){return this->damage;} //return damage of item


    Potion::Potion(){ //default constructor must initialize the type of item
      this->type = "Potion";
      this->amount = 0;
    }

    Potion::Potion(int healing) {  //second constructor must also initialize type
      this->healing = healing;
      this->type = "Potion";
    }

    void Potion::setHealing(int healing) {this->healing = healing;} //set healing value


    void Potion::setAmount(int amount) {this->amount = amount;} //set amount of potions

    int Potion::getHealing(){return this->healing;} //return healing value

	int Potion::getAmount(){return this->amount;}
/*character*/
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

//@caleb this getWeapon isn't defined look at this
//void Character::gotAWeapon() {
  //this->offense = this->offense + getWeapon();
//}


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
/*monster*/
Monster::Monster(int health, int attack, int x, string Name)
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
  return health;
}

int Monster::getEscape(){
  return escape;	
}

void Monster::decHealth(int attackPower){
	this->health-=attackPower;
}

int Monster::ptak(int currHealth){
 cout<<"Your current health is " << currHealth << " but not for long!" << endl;
 int canAttack = rand() % (5);
 if(canAttack==0) {
	cout<< "Oh no! I missed! How is that possible!?";
	return 0;
 }
 else{
	return attack;
 }
}
