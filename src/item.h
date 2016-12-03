<<<<<<< HEAD
class Item {
  private:
    String type;
    int cost;
  public:
    void setType(String type);
    void setCost(int cost);
    String getType();
    int getCost();
     
};

Item::Item(String type, int cost) {
  this->type = type;
  this->cost = cost;
}

void setType(String type){
  this->type = type;
}

void setCost(int cost){
  this->cost = cost;
}

String getType(){
  return this->type;
}

int getCost(){
  return this->cost;
}
=======
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
    Weapon(int damage) {  //second constructor must also initialize type
      this->damage = damage;
      this->type = "Weapon";
    }

    void setDamage(int damage) {this->damage = damage;} //set damage of item

    int getDamage(){return this->damage;} //return damage of item

};

//Potion Class is an extension of Item Class
class Potion  : public Item {

  private:  //healing variable is visible by only the Weapon class
    int healing;
    int amount;

  public:

    Potion(){ //default constructor must initialize the type of item
      this->type = "Potion";
      this->amount = 0;
    }

    Potion(int healing) {  //second constructor must also initialize type
      this->healing = healing;
      this->type = "Potion";
    }

    void setHealing(int healing) {this->healing = healing;} //set healing value

    void setAmount(int amount) {this->amount = amount;} //set amount of potions

    int getHealing(){return this->healing;} //return healing value

};
>>>>>>> origin/Tyler
