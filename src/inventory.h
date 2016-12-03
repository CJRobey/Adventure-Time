#include <iostream>
#include <string>
#include "item.h"
#include <map>
#include <sstream>

using namespace std;

class Inventory {

  private:
    map<string, Weapon> Weapons;
    map<string, Potion> Potions;

  public:
    Inventory(){}
    Inventory(map<string, Weapon> Weapons, map<string, Potion> Potions) {
        this->Weapons = Weapons;
        this->Potions = Potions;
    }

    void disInventory(){
        Weapon iteratedWeapon;
        Potion iteratedPotion;
        string name, damage, worth, spaces, cost, healing, amount= "";
        int length,attribute;
        stringstream ss;
        spaces = "                    ";
        cout << endl << "\t|~|~|~|~|~|~|~|~|~|~| INVENTORY |~|~|~|~|~|~|~|~|~|~|" << endl << endl;
        cout << "\tWeapon         Damage    Price     Worth" << endl;
        for(map<string, Weapon>::iterator iter = Weapons.begin(); iter != Weapons.end(); ++iter) {
            iteratedWeapon = Weapons[iter->first];
            name = iteratedWeapon.getName();
            length = name.length();
            cout << "\t" << name << spaces.substr(0,15-length);
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
            cout << worth << endl;
        }
        cout << endl;
        cout << "\tPotion         Healing   Price     Worth     Amount" << endl;
        for(map<string, Potion>::iterator iter2 = Potions.begin(); iter2 != Potions.end(); ++iter2) {
            iteratedPotion = Potions[iter2->first];
            name = iteratedPotion.getName();
            //cout << "Name is " << name << endl;
            length = name.length();
            //cout << "Length of name is " << length << endl;
            cout << "\t" << name << spaces.substr(0,15-length);
            attribute = iteratedPotion.getHealing();
            ss << attribute;
            healing = ss.str();
            ss.str("");
            length = healing.length();
            cout << healing << spaces.substr(0,10-length);
            attribute = iteratedPotion.getCost();
            ss << attribute;
            cost = ss.str();
            ss.str("");
            length = cost.length();
            cout << cost << spaces.substr(0,10-length);
            attribute = iteratedPotion.getWorth();
            ss << attribute;
            worth = ss.str();
            ss.str("");
            length = worth.length();
            cout << worth << spaces.substr(0,10-length);
            attribute = iteratedPotion.getAmount();
            ss << attribute;
            amount = ss.str();
            ss.str("");
            cout << amount << endl;
        }
        cout << endl;
        cout << "\t|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|~|" << endl << endl;
    }

    void drop(Potion P) {
        usePotion(P.getName());
    }
    void drop(Weapon W) {
        removeWeapon(W.getName());
    }
    void add(Potion P) {
        addPotion(P.getName(),P);
    }
    void add(Weapon W) {
        addWeapon(W.getName(),W);
    }

    void addWeapon(string weaponName, Weapon W) {
        if (Weapons.find(weaponName) != Weapons.end())
            cout << "You already own that weapon!" << endl;
        else {
            Weapons[weaponName] = W;
            cout << weaponName << " has been added!" << endl;
        }
    }

    void removeWeapon(string weaponName) {
        if (Weapons.find(weaponName) != Weapons.end())
            cout << "You don't own that weapon!" << endl;
        else {
            Weapons.erase(weaponName);
            cout << weaponName << " has been removed." << endl;
        }
    }

    void addPotion(string potionName, Potion P) {
        if (Potions.find(potionName) != Potions.end())
            cout << "You already own that potion!" << endl;
        else {
            Potions[potionName] = P;
            cout << potionName << " has been added!" << endl;
        }
    }

    Potion usePotion(string potionName) {
        Potion P;
        if (Potions.find(potionName) != Potions.end())
            cout << "You don't own that potion!" << endl;
        else {
            P = Potions[potionName];
            Potions.erase(potionName);
            cout << potionName << " has been removed!" << endl;
        }
        return P;
    }
};
