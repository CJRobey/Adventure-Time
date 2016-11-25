
class Item {
  private:
    String type;
    int cost;
  public:
    void setType(String type);
    void setCost(int cost);
    String getType();
    int getCost();
     
};

Item::Item(String type, int cost) {
  this->type = type;
  this->cost = cost;
}

void setType(String type){
  this->type = type;
}

void setCost(int cost){
  this->cost = cost;
}

String getType(){
  return this->type;
}

int getCost(){
  return this->cost;
}
