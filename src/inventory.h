#include <iostream>
#include <string>
#include "item.h"
#include <map>

using namespace std;

class Inventory {

  private:
    map<string, Weapon> Weapons;
    map<string, Potion> Potions;

  public:
    Inventory(){}
    Inventory(list<item> Items) {this->Items = Items;}

    void displayInventory(){

    }

    void addWeapon(string weaponName, Weapon W) {
        if (Weapons.find(weaponName) != Weapons.end())
            cout << "You already own that weapon!" << endl;
        else
            Weapons["weaponName"] = W;
            cout << weaponName << " has been added!" << endl;
    }

    void removeWeapon(string weaponName) {
        if (Weapons.find(weaponName) != Weapons.end())
            cout << "You don't own that weapon!" << endl;
        else
            Weapons.erase(weaponName);
            cout << weaponName << " has been removed."
    }

    void addPotion(string potionName, Potion P) {
        if (Potions.find(potionName) != Potions.end())
            cout << "You already own that potion!" << endl;
        else
            Potions["potionName"] = P;
            cout << potionName << " has been added!" << endl;
    }

    void removePotion(string potionName) {
        if (Potions.find(potionName) != Potions.end())
            cout << "You don't own that potion!" << endl;
        else
            Potions.erase(potionName);
            cout << potionName << " has been removed!" << endl;
    }
}
