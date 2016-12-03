
#include "inventory.h" 
#include "item.h"
#include "AdventureTime.h"

class Store {
  private:
    Inventory* inventory;
  public:
    void setInventory(Inventory inventory);
    Inventory getInventory();
    bool buy(Item i);
    int sell(Item i);
    string print();
};

Store::Store(Inventory inventory) {
 this->inventory = new Inventory(inventory);
}

void setInventory(Inventory inventory) {
  this->inventory = new Inventory(inventory);
}

Inventory getInventory(){
   return this->inventory;
}

//Character can call only if they have enough money.
//Inventory item should check if item is in the store

bool buy(Item i){
  if(inventory.isIn(i)) return true;
  else{
    return false;
  }
}

int sell(Item i){
  return i.getCost();
}

int print() {
   
}
