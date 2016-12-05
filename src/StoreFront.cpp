#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include "Character.cpp"
#include <time.h>

//pausing function for aesthetic reasons
void wait ( int seconds )
{
  clock_t endwait;
  endwait = clock () + seconds * CLOCKS_PER_SEC ;
  while (clock() < endwait) {}
}



using namespace std;

class Store
{
  private:

    //the constructor of Weapon is (buying Price, selling price, name, and damage)
	   Weapon wepInventory [16] = {Weapon(180,108,"Swiss_Army_Rock",10), Weapon(210,126,"Rusty_Spork",15), Weapon(240,144,"Dubious_Dagger",20), Weapon(270,162,"Mediocre_Spear",25), Weapon(470,282,"Brutal_Maul",40),
     Weapon(500,300,"Undertakers_Cleaver",50), Weapon(530,318,"Nunchucks_of_Unending_Smiting",60), Weapon(560,336,"Absurdly_Sharp_Lance",70), Weapon(960,576,"Devastating_Flail",120), Weapon(1020,612,"Legendary_Longsword",140),
     Weapon(1080,648,"Soulstealing_Demonblade",160), Weapon(1140,684,"Blade_of_Eternal_Gods",180), Weapon(2230,1338,"Paintbrush_of_the_Devil",340), Weapon(2290,1374,"Blackhole_Hammer",380), Weapon(2350,1410,"Dimension_Bifurcating_Battleax",420),
     Weapon(2410,1446,"The_Big_Bang_Cannon",460)} ;
     Character *c;

  public:
    Store(Character &c);
    void getWepInventory();
    void buyPotion();
    void getCharInventory();
    string getName();
    void buy(Weapon i);
    int sell(Item i);
    bool openStore();
};

//this is a super-hype way of changing all the data fields of character, including the inventory... the most important part.
//but you're also able to change gold, which is cool.
Store::Store(Character &c) {
  this->c = &c;
}


//this method will open the store and get things going. It needs to be wrapped in a loop in the main method
//for it to continue until the user is done
bool Store::openStore() {
  string currentResponse;
  cout << "Would you like to buy or sell today?\n";
  wait(1);
  cout << "Or if you've got no business here, I'll need to ask you to leave.\n(Please enter buy, sell, or leave)\n";
  cin >> currentResponse;
  wait(1);
  //buying either a weapon or a potion.
  if(currentResponse=="buy")
  {
    string resp;
    cout << "Would you like to buy weapons or potions?\n(Please enter weapons or potions.)\n";
    cin >> resp;
    wait(1);
    cout << endl;
    if(resp=="weapons")  {
      getWepInventory();
    }
    //this essentially just increments the potion count and decrements user gold.
    else if(resp=="potions"){
      if((c->getGold() >= c->getInv().getPotCost()) && (c->getInv().getPotCount() < 10)){
      buyPotion();
    }
    else if (c->getGold() < c->getInv().getPotCost()){
      cout << "You do not have enough money to purchase this item." << endl;
    }
    else if (resp=="potions" && (c->getInv().getPotCount() == 10)){
      cout << "Your potion inventory is full! You can't buy any more potions." << endl;
    }
    else{
      cout << "Not a valid input." << endl;
    }
  }
}
  else if(currentResponse=="leave")  {
    cout << "You leave the store." << endl;
    wait(1);
    cout << endl;
    return false;
  }
  else if(currentResponse=="sell")  {

    cout << "Please enter either 'potion' or the name of the weapon you would like to sell:" << endl;
    string item;
    cin >> item;

    if (item == "potion") {
        //sellPotion() returns the selling value of the potion
        int money = c->sellPotionChar();
        if (money == 0) {
          return true;
        }
        c->incGold(money);
    }
  else {
    int moneyBack = c->remInvWeapon(item);
    if(moneyBack != 0) {
       c->incGold(moneyBack);
    }
  }
}
return true;
}

void Store::getWepInventory() {

  cout << "Here is what we have for sale: " << endl;

  //display the available weapons with their costs.
  int wepArrSize = (sizeof(wepInventory)/sizeof(wepInventory[0]));

  for (int i = 0; i < wepArrSize; i++) {
    cout << (i+1) << ". " << wepInventory[i].getName() << " || Cost: " << wepInventory[i].getCost() << "\n";
    wait(1);
    cout << endl;
  }

  cout << "If you're not interested, please enter '0' to return to the main menu. Please enter the number associated with the weapon that you would like to choose: " << endl;
  int choose;

    cout << "enter number: ";

    int num;
		while(!(cin >> num) || num < 0 || num > wepArrSize+1){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout<<"Invalid input: please choose again"<<endl;
		}
    choose = num;
    cout << endl;
    if (choose == 0) {
      return;
    }
    else if (choose >= 0 && choose <= (wepArrSize+1)) {
      //reference a buy method which will check for the amount of gold being availabe
      buy(wepInventory[choose-1]);
      return;
    }
}

void Store::buyPotion() {
  int price = c->addPotionToInv();
  c->decGold(price);
  cout << "You have added a potion to your inventory for " << price << " gold coins." << endl;
  cout << "You now have " << c->getInv().getPotCount() << " potions out of your 10 available slots." << endl;
}


void Store::buy(Weapon w) {
  if (w.getCost() > c->getGold()) {
    cout << "You do not have enough money to purchase this item." << endl;
    cout << "this item costs " << w.getCost() << " gold, and you only have " << c->getGold() << endl;
    return;
  }
  else if (c->getInv().isElemOfWeap(w.getName())) {
    cout << "You already have this item. No need to purchase it again." << endl;
    return;
  }
  else {
    c->addInvWeapon(w);
    c->decGold(w.getCost());
    cout << "Congratulations! You have purchased a brand new " << w.getName() << "!" << endl;
    c->incOffense(c->getInv().getWeapon());
  }
}
