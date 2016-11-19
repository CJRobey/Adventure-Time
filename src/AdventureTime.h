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
  struct Item(string itemType, int cost);
  string getType();
  int getCost();

}

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
  struct Weapon(string weapType, int damage);
  string getType();
  string getDamage();
}

class Potion: public Item
{
private:
  string type;
  int recovPoints
  /*Also think that cost should be taken care of in the item superclass*/
public:
  struct Potion(int recovPoints);
  string getType();
  int getRecovPoints();

}


class Inventory
{
private:



}



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

        struct Character(string name, string type);
        string getName();
        void attack(Character opponent);
        void heal(int potionIndex);
        void run();


}
