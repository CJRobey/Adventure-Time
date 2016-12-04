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
	   Weapon wepInventory [5] = {Weapon(5,3,"Rusty Spork",50), Weapon(20,12,"Dubious Dagger",70), Weapon(50,30,"Nunchucks of Unending Smiting",100),
   Weapon(70,42,"Absurdly Sharp Lance",200), Weapon(300,180,"Blade of Eternal Gods",300)} ;
     Character c;

  public:
    Store(Character &c);
    void getWepInventory();
    void buyPotion();
    void getCharInventory();
    string getName();
    void buy(Weapon i);
    int sell(Item i);
    void openStore();
};

//this is a super-hype way of changing all the data fields of character, including the inventory... the most important part.
//but you're also able to change gold, which is cool.
Store::Store(Character &c) {
  this->c = c;
}


//this method will open the store and get things going. It needs to be wrapped in a loop in the main method
//for it to continue until the user is done
void Store::openStore() {
  string currentResponse;
  cout << "Hey there!\n";
  wait(1);
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
      buyPotion();
    }
    else{
      cout << "Not a valid input." << endl;
      return;
    }
  }

  else if(currentResponse=="sell")  {

    cout << "Please enter either 'potion' or the name of the weapon you would like to sell:" << endl;
    string item;
    cin >> item;

    if (item == "potion") {
        //sellPotion() returns the selling value of the potion
        int money = c.getInv().sellPotion();
        if (money == 0) {
          return;
        }
        c.incGold(money);
    }
    int moneyBack = c.getInv().drop(item);
    if(moneyBack != 0) {
       c.incGold(moneyBack);
    }


  }
  else if(currentResponse=="leave")  {
    cout << "You leave the store." << endl;
    wait(2);
    cout << endl;
    return;
  }
  else {
    cout << "Not a valid input." << endl;
    wait(2);
    cout << endl;
    return;
  }

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
  int price = c.addPotionToInv();
  c.decGold(price);
  cout << "You have added a potion to your inventory for " << price << " gold coins." << endl;
  cout << "You now have " << c.getInv().getPotCount() << " potions out of your 10 available slots." << endl;
}


void Store::buy(Weapon w) {
  if (w.getCost() > this->c.getGold()) {
    cout << "You do not have enough money to purchase this item." << endl;
    cout << "this item costs " << w.getCost() << " gold, and you only have " << this->c.getGold() << endl;
    return;
  }
  else if (c.getInv().isElemOfWeap(w.getName())) {
    cout << "You already have this item. No need to purchase it again." << endl;
    return;
  }
  else {
    c.addInvWeapon(w);
    c.decGold(w.getCost());
    cout << "Congratulations! You have purchased a brand new " << w.getName() << "!" << endl;
    c.incOffense(c.getInv().getWeapon());
  }
}
