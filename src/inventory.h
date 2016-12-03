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
    void disInventory();
    int drop(string itemName);
    void add(Potion P);
    void add(Weapon W);
    int usePotion(string potionName);
    int getWeapon();
};

    void Inventory::disInventory(){
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

    int Inventory::drop(string itemName) {
        int worth;
        if (Weapons.count(itemName)) {
            worth = Weapons[itemName].getWorth();
            Weapons.erase(itemName);
            cout << itemName << " has been removed." << endl;
        }
        else if (Potions.count(itemName)) {
            worth = Potions[itemName].getWorth();
            if (Potions[itemName].getAmount() > 1){
            Potions[itemName].setAmount(Potions[itemName].getAmount() - 1);
            cout << "1 " << itemName << " has been removed" << endl;
            }
            else {
                Potions.erase(itemName);
                cout << itemName << " has been removed." << endl;
            }
        }
        else {
            cout << "You don't own that item!" << endl;
            worth = 0;
        }
        return worth;
    }

    void Inventory::add(Potion P) {
        string potionName = P.getName();
        if (Potions.count(potionName))
            cout << "You already own that potion!" << endl;
        else {
            Potions[potionName] = P;
            cout << potionName << " has been added!" << endl;
        }
    }

    void Inventory::add(Weapon W) {
        string weaponName = W.getName();
        if (Weapons.count(weaponName))
            cout << "You already own that weapon!" << endl;
        else {
            Weapons[weaponName] = W;
            cout << weaponName << " has been added!" << endl;
        }
    }

    int Inventory::usePotion(string potionName) {
        Potion P;
        int healing;
        if (!Potions.count(potionName))
            cout << "You don't own that potion!" << endl;
        else if (Potions[potionName].getAmount() > 1){
            P = Potions[potionName];
            healing = P.getHealing();
            Potions[potionName].setAmount(Potions[potionName].getAmount() - 1);
            cout << "1 " << potionName << " has been removed" << endl;
        }
        else {
                P = Potions[potionName];
                healing = P.getHealing();
                Potions.erase(potionName);
                cout << potionName << " has been removed." << endl;
        }
        return healing;
    }

    int Inventory::getWeapon() {
        Weapon currentWeapon;
        Weapon strongestWeapon;
        int maxDamage = 0;
        for(map<string, Weapon>::iterator iter = Weapons.begin(); iter != Weapons.end(); ++iter) {
            currentWeapon = Weapons[iter->first];
            if (currentWeapon.getDamage() > maxDamage) {
                maxDamage = currentWeapon.getDamage();
            }
            return maxDamage;
        }
    }
