#include <iostream>
#include <string>
#include <fstream>
#include "StoreFront.cpp"

using namespace std;

void getFileContents (string fileName)
{
		ifstream Reader (fileName);             //Open file

		string Lines = "";        //All lines

		if (Reader)                      //Check if everything is good
		{
	while (Reader.good())
	{
			std::string TempLine;                  //Temp line
			std::getline (Reader , TempLine);        //Get temp line
			TempLine += "\n";                      //Add newline character

			Lines += TempLine;                     //Add newline
	}
	cout << Lines << endl;
		}
}

int main () {
	int i=1;

	Inventory inv = Inventory();

	string name = "Hero";
	Character *c = new Character(name, inv);
	getFileContents("Title.txt");

	while (i!=0) {
		cout<< "0 exit" << endl;
		cout<< "1 fight"<< endl;
		cout<< "2 get gold"<< endl;
		cout<< "3 use store"<< endl;
		cout<< "4 see stats"<< endl;
		cout<< "5 Level up" << endl;

		cin>>i;
		if (i==1) {
			Monster theThing = Monster(10,5,5,"Enemy");
			int i = c->battle(theThing);
			//if i = 0, you won the fight; i =1, you successfully ran, and if i = 2, you died.
		}
		if (i==2) {
			c->incGold(10000);
		}
		if (i==3) {
			//s.openStore(c, inv);
			Store *s = new Store(*c);
			s->openStore();
		}
		if (i==4) {
			c->dispCharStats();
		}
		if(i==5){
			c->levelUp();
		}
	}
	//delete c;

}
