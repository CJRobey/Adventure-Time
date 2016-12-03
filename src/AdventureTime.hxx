/* For now, let's try to keep it to one header file for the project, but we can
change this if necessary. */

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
    Monster(int health, int attack, int x, string Name);
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
    Item(string type, int cost, int worth, string name) ;

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

};


class Inventory {

  private:
    map<string, Weapon> Weapons;
    map<string, Potion> Potions;

  public:
    Inventory();
    Inventory(map<string, Weapon> Weapons, map<string, Potion> Potions);
    void disInventory();
    void drop(Potion P);
    void drop(Weapon W);
    void add(Potion P);
    void add(Weapon W);
    void addWeapon(string weaponName, Weapon W);
    void removeWeapon(string weaponName);
    void addPotion(string potionName, Potion P);
    void removePotion(string potionName);
    Potion usePotion(string potionName);
};


class Store 
{
  private:
	   Weapon wepinventory[];
     Potion potinventory[];
     
  public:
    void openStore();
    void getWepInventory();
    void getPotInventory();
    void getCharInventory();
    bool buy(int i);
    int sell(Item i);
    string currentResponse;
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
	 Character();
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


};
