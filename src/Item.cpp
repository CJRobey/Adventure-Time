#include <iostream>
#include <string>

using namespace std;

//Parent Item Class
class Item {

  protected:  //uses protected so that extensions can access these variables
    string type, name;
    int cost,worth;

  public:
    Item() {} //default constructor does not need to initialize anything
    Item(string type, int cost, int worth, string name) { //second constructor
      this->type = type;
      this->cost = cost;
      this->worth = worth;
      this->name = name;
    }

    void setName(string name){this->name = name;} //set name of item

    void setCost(int cost){ //set cost and therefore worth of item
      this->cost = cost;
      this->worth = int(cost*0.6);  //worth is 60% of initial cost
    }

    string getName(){return this->name;}  //return name of item

    string getType(){return this->type;}  //return type of item

    int getCost(){return this->cost;} //return cost of item

    int getWorth(){return this->worth;} //return worth of item
};

//Weapon Class is an extension of Item Class
class Weapon  : public Item {

  private:  //damage variable is visible by only the Weapon class
    int damage;

  public:

    Weapon(){ //default constructor must initialize the type of item
      this->type = "Weapon";
    }
    Weapon(int cost, int worth, string name, int damage) {  //second constructor must also initialize type
      this->damage = damage;
      this->type = "Weapon";
      this->name = name;
      this->cost = cost;
      this->worth= worth;
    }

    void setDamage(int damage) {this->damage = damage;} //set damage of item

    int getDamage(){return this->damage;} //return damage of item
    string getName(){return this->name;}  //return name of item

};

//Potion Class is an extension of Item Class
class Potion  : public Item {

  private:  //healing variable is visible by only the Weapon class
    int healing;

  public:

    Potion(){ //default constructor must initialize the type of item
      this->type = "Potion";
    }

    Potion(int healing) {  //second constructor must also initialize type
      this->healing = healing;
      this->type = "Potion";
      this->cost = 30;
    }

    void setHealing(int healing) {this->healing = healing;} //set healing value

    int getHealing(){return this->healing;} //return healing value
    void setWorth(int i) {
      this->worth = i;
    }

};
