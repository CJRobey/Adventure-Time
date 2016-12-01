/* For now, let's try to keep it to one header file for the project, but we can
change this if necessary. */

#include <string>
#include <cstdlib>
using namespace std;


/*This class will be extended into "weapon," "potion," and possibly a few other
types*/
class Item
{
private:
  string itemType;
  int cost;

public:
  Item(string itemType, int cost);
  string getType();
  int getCost();

};

class Weapon: public Item
{
private:
  /*I believe that we were also considering only making certain weapons
  available at certain levels and I don't know if that should be implemented
  here*/
  string weapType;
  int damage;
  /*We had a cost variable listed in the UML, but I think that was wrong since
  we are extending item*/
public:
  Weapon(string weapType, int damage);
  string getType();
  string getDamage();
};

class Potion: public Item
{
private:
  string type;
  int recovPoints;
  /*Also think that cost should be taken care of in the item superclass*/
public:
  Potion(int recovPoints);
  string getType();
  int getRecovPoints();

};


class Inventory
{
private:
  Item* weapons;
  Item* potions;
  int activeWeapon;

public:
  Inventory(Item* weapons, Item* potions);
  Inventory();
  /*picking specific getters and setter will probably be relatively dynamic*/
  int getActiveWeapon();
  Item* getListOfWeapons();
  Item* getListOfPotions();
  void displayInventory();
  void drop(Item i);
  void add(Item i, string type);
};
