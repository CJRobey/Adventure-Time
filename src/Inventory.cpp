#include <iostream>
#include <fstream>
#include <string>
#include "Item.cpp"
#include <map>
#include <sstream>

using namespace std;

class Inventory {

  private:
    map<string, Weapon> Weapons;	//creates hashmap of Weapon objects
    Potion P;	//creates one Potion object
    int potCount;	//count variable for potions

  public:
    Inventory();	//default constructor
    void disInventory();	//display contents of Inventory function
    int drop(string itemName);	//sell a Weapon function
    void addPotion();	//add a potion to inventory
    void addWeapon(Weapon W);	//add a weapon to inventory
    int usePotion();	//remove a potion from inventory and return the amount of healing it does
    int getWeapon();	//returns the aggregate damage value of the weapons
    void setPotionAmount(int amount);	//set the amount of Potion P
    void setPotionHealing(int healing);	//set the healing value of Potion P
    void setPotionCost(int cost);	//set the cost value of Potion P
    int getPotionCost();	//returns the cost of Potion P
    int getPotionHealing();	//returns the healing value of Potion P
    bool isElemOfWeap(string s);	//checks to see if the weapon is already in the Weapons hashmap
    map<string, Weapon>* getWeaponMap();	//returns the Weapon hashmap
    int getPotCount();	//returns the amount of Potion P in inventory
    Potion getPotion();	//returns Potion P
    int sellPotion();	//decrements the amount of Potion P and returns the selling price as an int
    int getPotCost();	//returns the cost value of Potion P
    void getFileContents(string fileName);	//reads in files for ASCII pictures
};

Inventory::Inventory() {
  /*instantiate a level one character Inventory, which contains nothing.*/
  this->potCount = 0;

}

void Inventory::getFileContents (string fileName)
{
		ifstream Reader (fileName);             //Open file

		string Lines = "";        //All lines

		if (Reader)                      //Check if everything is good
		{
	while (Reader.good())
	{
			string TempLine;                  //Temp line
			getline (Reader , TempLine);        //Get temp line
			TempLine += "\n";                      //Add newline character

			Lines += TempLine;                     //Add newline
	}
	cout << Lines << endl;
		}
}

int Inventory::getPotCost() {
  return P.getCost();
}


int Inventory::sellPotion() {
  if(potCount > 0) {
  this->potCount--;
  cout << "You sold a potion" << endl;
  return P.getWorth();
  }
  else {
    cout << "You don't have any potions to sell" << endl;
    return 0;
  }


}

Potion Inventory::getPotion() {
  return P;
}

int Inventory::getPotCount() {
  return potCount;
}

map<string, Weapon>* Inventory::getWeaponMap() {
  return &Weapons;
}


    void Inventory::disInventory()
    {
      Weapon iteratedWeapon;
      string name, damage, worth, spaces, cost, healing, amount= "";
      int length,attribute;
      stringstream ss;
      spaces = "                              ";
      cout << endl << "\t|~|~|~|~|~|~|~|~|~|~|~|~|~|~| INVENTORY |~|~|~|~|~|~|~|~|~|~|~|~|~|~|" << endl << endl;
      cout << "\tName                          Effect    Price     Worth     Amount" << endl;
      for(map<string, Weapon>::iterator iter = Weapons.begin(); iter != Weapons.end(); ++iter)	//iterator parses through Weapons hashmap and prints out the contents
      {
        iteratedWeapon = Weapons[iter->first];
        name = iteratedWeapon.getName();
        length = name.length();
        cout << "\t" << name << spaces.substr(0,30-length);	//finds correct spacing to keep columns aligned
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
        length = worth.length();
        cout << worth << spaces.substr(0,10-length) << "1" << endl;
      }
      cout << "\t" << "Potion" << spaces.substr(0,24);	//prints out contents of Potion P in line with the contents of the Weapons hash map
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
      attribute = potCount;
      ss << attribute;
      amount = ss.str();
      ss.str("");
      cout << amount << endl;
      cout << endl;
      cout << "\t|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|" << endl << endl;
    }

    int Inventory::drop(string itemName) {
        int worth;
        map<string, Weapon>::iterator it;
        if (Weapons.count(itemName)) {	//checks to see if the weapon is in the Weapons hash map
            worth = Weapons[itemName].getWorth();
            it = Weapons.find(itemName);
            Weapons.erase(it);
            cout << itemName << " has been removed." << endl;
        }

        else if (!itemName.compare(P.getName())) {	//checks to see if the string is equal to 'Potion'
            if (potCount >= 1) {
                potCount--;
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

    void Inventory::addPotion() {
        this->potCount++;
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
        if(potCount > 0) {
            this->potCount--;
            healing = P.getHealing();
        }
        else {
            healing = 0;
            cout << "You do not own enough potion!" << endl;
        }
        return healing;
    }

    int Inventory::getWeapon() {	//iterates through the Weapons hash map and returns the largest damage value of the weapons
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

    bool Inventory::isElemOfWeap(string s) {
      if (Weapons.count(s) == 1) {
        return true;
      }
      else return false;
    }


    void Inventory::setPotionHealing(int healing) {P.setHealing(healing);} //set healing value

    void Inventory::setPotionCost(int cost) {P.setCost(cost);}

    int Inventory::getPotionHealing(){return P.getHealing();} //return healing value
