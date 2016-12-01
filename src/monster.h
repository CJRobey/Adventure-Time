#include "item.h";
class Monster {
  private:
    int attack;
    int health;
    Item* items = new Item[10];
    
  public:
    int getAttack();
    int getHealth();
    int isAttacked();
    void setAttack();
    void setHealth();
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

void isAttacked(){
  //print updated monster stats--> if dead make a big deal;
}
