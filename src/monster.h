#include "item.h";
class Monster {
  private:
    int attack;
    int health;
    Item* items = new Item[10];
    
  public:
    int getAttack();
    int getHealth();
    void setAttack();
    void setHealth();
    void decHealth(int attackPower);
    void ptak();
};

Monster::Monster(int level)
{

}

int getAttack(){
  return attack;
}

int getHealth(){
  return health;
}

void decHealth(int attackPower){
  
  //print updated monster stats--> if dead make a big deal;
}

void ptak(Character* char){
 //print character points
}
