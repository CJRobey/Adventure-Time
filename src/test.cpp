#include <iostream>
#include <string>
#include "Everydef.hxx"

using namespace std;
int main () {
	int i=1;
	Inventory inv;
	Character* c = new Character("Hero", inv);
	Store s;
	while (i!=0) {
		cout<< "0 exit" << endl;
		cout<< "1 fight"<< endl;
		cout<< "2 get gold"<< endl;
		cout<< "3 use store"<< endl;
		cout<< "4 see stats"<< endl;
		cin>>i;
		if (i==1) {
			bool boo = c->battle(Monster(10,5,5,"Enemy"));
		}
		if (i==2) {
			c->incGold(10000);
		}
		if (i==3) {
			//s.openStore(c, inv);
		}
		if (i==4) {
			c->dispCharStats();
		}
	}
	//delete c;
	
}
