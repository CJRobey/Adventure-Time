#include <iostream>
#include <string>
#include "AdventureTime.hxx"

using namespace std;

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
