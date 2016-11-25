#include "inventory.h" 
#include "item.h"

class Store {
  private:
    Inventory* inventory;
  public:
    void setInventory(Inventory inventory);
    Inventory getInventory();
    void buy(Item i);
    void sell(Item i);
};

Store::Store(Inventory inventory) {
 this->inventory = new Inventory(inventory);
}
