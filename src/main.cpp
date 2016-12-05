#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <limits>
#include "Plot.cpp"
#include "StoreFront.cpp"

using namespace std;

bool chance(int luck) { //this function returns a boolean based on a given chance

	if ((rand() * 100) < luck) {
		return true;
	}
	else return false;
}

void getFileContents (string fileName) //this function is used to display the ascii text
{
		ifstream Reader (fileName);             //Open file
		string Lines = "";        //All lines
		if (Reader)                      //Check if everything is good
		{
	while (Reader.good())
	{
			string TempLine;                  //Temp line
			getline (Reader , TempLine);        //Get temp line
			TempLine += "\n";                      //Add newline character
			Lines += TempLine;                     //Add newline
	}
	cout << Lines << endl;
		}
}

int input(int choices, Character *c) { //this function makes sure that the input is valid and displays character info
	int pChoice;
	while (true) {
		cout << "\n";
		int num;
		while(!(cin >> num)){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout<<"Please enter a valid choice:\n";
		}
		pChoice=num;
	if ((pChoice >=0 && pChoice<=choices)) {
		if (pChoice==0){
			c->dispCharStats();
		}
		if (pChoice!=0) {
		return pChoice;
	}
	}
	cout<<"Please enter a valid choice:\n";

	}
}

bool Death(Character *character) { //handles the option to quit if the character dies
	getFileContents("GrimReaper.txt");
	cout<<"Do you want to continue?\n\t1: Yes\n\t2: No\n";
	int pChoice = input(2,character);
	if (pChoice==1) {
		return true;
	}
	else {
		return false;
	}
}


int main () {
	string pName;
	int save = 1;
	int pChoice = 7;
	int helped = 0;
	int startGold = 500;
	bool end = false;
	bool found = false;
	bool leftRoom = false;
	bool rightRoom = false;
	bool seenBeggar = false;
	bool moreGold = false;
	string pResponse = "";
	int battRes=7;
	Inventory i;
	Plot plot;
	Monster mon = Monster(0,0,0,"");


	getFileContents("Title.txt");
	cout<<"\nEnter 0 at any point to see your inventory.\n\n";
	cout<<"\nWhat is your name?\n";
	cin>>pName;
	Character *character = new Character(pName, i);

	if (pName==";") { //creates developer mode
		cout << "ur a dev.\n";
		character->setMaxHealth(50000);
		character->incHealth(50000);
		character->incOffense(50000);
		character->incGold(50000);
	}
	cout<<"Demo Mode?\n1: Yes\n2: No";
	pChoice=input(2,character);
	if (pChoice==1) { //enters demo mode
		save=5;
	}
	while (!end) { //encompassing while statement runs the code until the game ends
	switch (save) {//switch statement allows for save points

			/*We used if and nested if statements to build the plotline. In order
to make main more manageable, we used the serperate class plot to keep
track of the storyline strings*/


	case (1): {
		cout << plot.text[0] << plot.text[1];

		while(pChoice != 1){

			cout << plot.text[2];
			pChoice=input(3,character);

			if(pChoice == 1){
				cout << plot.text[3];
				character->incGold(startGold);
			}
			if(pChoice == 2){
				cout << plot.text[4];
			}
			if(pChoice == 3&&!moreGold){

				if (chance(50)){
					cout << plot.text[5];
					startGold = 750;
					moreGold=true;
				}
				else {
					cout << plot.text[6];
							moreGold=true;
				}
			}
			if (pChoice==3&&moreGold) {
				cout<<"You've already done that";
			}

		}


	cout << plot.text[7];
	while (pChoice != 2){

		cout<<plot.text[8];
		pChoice = input(2,character);


	if(pChoice == 1){
		cout << plot.text[9];
		character->decGold(1);
	}
	if(pChoice == 2){
		cout << plot.text[10];
		pChoice = input(2,character);
		if(pChoice == 1){
			cout << plot.text[11];
			character->incGold(50);
		}
		if(pChoice == 2){
			cout << plot.text[12];
		}
		cout << plot.text[13];
			Store *s = new Store(*character);
			bool b = true;
			while(b){
				b = s->openStore();
			}
			pChoice = 2;
		cout << plot.text[14];
	}

	}

	cout << plot.text[15];
	cout << plot.text[16];
	pChoice = input(2,character);

	if(pChoice == 1){
		getFileContents("Wolf.txt");
		mon = Monster(40,10,90,"Wolves");//fight wolves
		battRes=character->battle(mon);
		if (battRes==2) {
			if (!Death(character)) {
				save = 0;
			}
			break;
		}

	}


	cout << plot.text[17];
	cout << plot.text[18];
	pChoice = input(2,character);

	if(pChoice == 1){
		cout << plot.text [19];
		character->incGold(20);
		cout << plot.text[20];
		pChoice = input(2,character);

		if(pChoice == 1){
			cout << plot.text[22];
			cout << plot.text[23];
			pChoice = input(3,character);

			if(pChoice == 1){
				getFileContents("Bandits.txt");
				mon = Monster(50,15,80,"Bandits");//fight bandits
				battRes = character->battle(mon);
				if (battRes==0) {
				cout << plot.text[24];
				character->incGold(200);
				helped++;
				}
				if (battRes==1) {
					cout << plot.text[25];
				}
				}

			if(pChoice == 2){
				if(chance(40) == true){
					getFileContents("Bandits.txt");
					mon = Monster(40,10,80,"Bandits");//fight bandits
					battRes = character->battle(mon);
					if (battRes==0) {
						cout << plot.text[24];
						character->incGold(200);
						helped++;
					}
				if (battRes==1) {
					cout << plot.text[25];
				}
				}
				else {
					getFileContents("Bandits.txt");
					mon = Monster(50,15,80,"Bandits");//fight bandits
					battRes = character->battle(mon);
					if (battRes==0) {
						cout << plot.text[24];
						character->incGold(200);
						helped++;
					}
					if (battRes==1) {
						cout << plot.text[25];
					}
					helped++;
				}
			}
			if(pChoice == 3){
				if(chance(60) == true){
					cout << plot.text[25];
				}
				if(chance(60) == false){
					getFileContents("Bandits.txt");
					mon = Monster(50,15,80,"Bandits");//fight bandits
					battRes = character->battle(mon);
					if (battRes==0) {
						cout << plot.text[24];
						character->incGold(200);
						helped++;
					}
					if (battRes==1) {
						cout << plot.text[25];
					}

				}
			}

		}
	}
	cout<<plot.text[26];
	}

	case (2): {
		save=2;
		cout<<plot.text[27];
		pChoice = input(2,character);

		if (pChoice==1) {
			cout<<plot.text[28];
			character->incHealth(20);
			getFileContents("Goblins.txt");
			mon = Monster(50,30,90,"Goblins"); //fights goblins
			battRes = character->battle(mon);
				if (battRes==2) {
					if (!Death(character)) {
						save = 0;
					}
					break;
				}

		}
		if (pChoice==2) {
			cout<<plot.text[29];
			getFileContents("Goblins.txt");
			mon = Monster(40,20,90,"Goblins"); //fights goblins
			battRes = character->battle(mon);
				if (battRes==2) {
					if (!Death(character)) {
						save = 0;
					}
					break;
				}
		}
		cout<<plot.text[30];
		cout<<plot.text[31];
		pChoice = input(2,character);
		while (pChoice!=2) {
			getFileContents("Goblins.txt");
			mon = Monster(40,20,90,"Goblins"); //fights goblins
			battRes = character->battle(mon);
				if (battRes==2) {
					if (!Death(character)) {
						save = 0;
					}
					break;
				}
			cout<<plot.text[30]<<plot.text[31];
			pChoice = input(2,character);
		}
		cout<<plot.text[33];
		pChoice = input(2,character);
		if (pChoice==2) {
			cout<<plot.text[35];
			cout<<plot.text[36];
			int numCorrect=0;
			cin>>pResponse;
			if (pResponse=="dark"||pResponse=="darkness") {
				cout<<"Correct";
				numCorrect++;
			}
			else {cout<<"Incorrect";}
			cout<<plot.text[37];
			cin>>pResponse;
			if (pResponse=="egg") {
					cout<<"Correct";
					numCorrect++;
			}
			else {cout<<"Incorrect";}
			cout<<plot.text[38];
			cin>>pResponse;
			if (pResponse=="time") {
				cout<<"Correct";
				numCorrect++;
			}
			else {cout<<"Incorrect";}
			if (numCorrect<2) {
				cout<<plot.text[39];
			}
			if (numCorrect>=2) {
				cout<<plot.text[40];
				cout<<plot.text[41];
				character->incGold(200);
				helped++;
			}
		}
		cout<<plot.text[42];
		pChoice = input(2,character);
		if (pChoice==2) {
			cout<<plot.text[43];
		}
		if (pChoice==1) {
			cout<<plot.text[44];
			while (pChoice!=2&&pChoice!=3) {
				cout<<plot.text[45];
				pChoice = input(4,character);
				if (pChoice==1) {
					Store *s = new Store(*character);
					while(s->openStore());
				}
				if (pChoice==4) {
					cout<<plot.text[46];
				}
			}
			if (pChoice==2) {
				cout<<plot.text[47];
				cout<<plot.text[48];
				pChoice = input(2,character);
				if (pChoice==1) {
					Store *s = new Store(*character);
					while(s->openStore());
				}
			}
			if (pChoice==3) {
				cout<<plot.text[49];
				getFileContents("Driver.txt");
				mon = Monster(200,30,50,"Carriage Driver");//fight carriage driver
				battRes = character->battle(mon);
				if (battRes==2) {
					if (!Death(character)) {
						save = 0;
					}
					break;
				}

				if (battRes==0) {
					helped++;
					cout<<plot.text[50];
				pChoice = input(3,character);
				cout<<plot.text[51];
				cout<<plot.text[52];
				pChoice = input(2,character);
					if (pChoice==1) {
						Store *s = new Store(*character);
						while(s->openStore()); //new store interactions
					}
				cout<<plot.text[53];
				}
			}


		}


	}

	case (3): {
		save=3;
		pChoice = 0;
		cout << plot.text[54];
		while(pChoice != 1 && pChoice!=2){
			cout << plot.text[55];
			pChoice = input(3,character);

			if(pChoice == 2){
				cout << plot.text[57];
				pChoice = input(2,character);
				if(pChoice == 1){
					cout << plot.text[59];
					pChoice = input(2,character);
					if(pChoice == 1){
						if(chance(50) == true){
							cout << plot.text[60];
							helped++;
						}
						else{
							cout << plot.text[61];
						}
					}
					if(pChoice == 2){
						cout << plot.text[62];
					}
				}
				if(pChoice == 2){
					cout << plot.text[58];
				}

			}
			if(pChoice == 3 && !found){
				cout << plot.text[56];
				found = true;
			}
			if(pChoice == 3 && found){
				cout << "You already investigated the bakery. Choose something else.";
			}
		}

		cout << plot.text[63];
		pChoice = input(2,character);

		if(pChoice == 1){
			cout << plot.text[64];
		}
		if(pChoice == 2){
			cout << plot.text[65];
		}

		cout << plot.text[66] << plot.text[67] << plot.text[68] << plot.text[69];
		pChoice = input(3,character);
		if(pChoice == 1){
			cout << plot.text[70];
		}
		if(pChoice == 2){
			cout << plot.text[71];
		}
		if(pChoice == 3){
			cout << plot.text[72];

			cout << plot.text[73];
			pChoice = input(3,character);

			//Choices 1 & 2 lead to same point
			if(pChoice == 1 || pChoice == 2){
				if(pChoice == 1){
					cout << plot.text[75];
					getFileContents("Thieves.txt");
					mon = Monster(250,40,50,"Thieves");//fight thieves
					battRes=character->battle(mon);
					if (battRes==2) {
								if (!Death(character)) {
									save = 0;
								}
								break;
							}
				}
				if(pChoice == 2){
					cout << plot.text[76];
					pChoice = input(2,character);
					if(pChoice == 1){
						getFileContents("Thieves.txt");
						mon = Monster(240,30,50,"Thieves");//fight thievs
						battRes=character->battle(mon);
						if (battRes==2) {
									if (!Death(character)) {
										save = 0;
									}
									break;
								}
					}
					if(pChoice == 2){
						cout << plot.text[77];
						getFileContents("Thieves.txt");
						mon = Monster(250,40,50,"Thieves");//fight thieves
						battRes=character->battle(mon);
						if (battRes==2) {
									if (!Death(character)) {
										save = 0;
									}
									break;
								}
					}
				}
				pChoice = 0;
				cout << plot.text[78];
				while(pChoice != 3){
					cout << plot.text[79];
					cin >> pChoice;
					if(pChoice == 1){
						if(leftRoom == true){
							cout << "You have already been here. Choose another option.";
						}
						else{
							cout << plot.text[80];
							character->incGold(1000);
							leftRoom = true;
						}
					}
					if(pChoice == 2){
						if(rightRoom == true){
							cout << "You have already been here. Choose another option.";
						}
						else{
							cout << plot.text[81];
							helped+=2;
							rightRoom = true;
						}
					}
				}
			}
			if(pChoice == 3){
				cout << plot.text[74];
			}
		}
		cout << plot.text[83];
		pChoice = 0;
		while(pChoice != 3){
			cout << plot.text[84];
			pChoice = input(3,character);

			if(pChoice == 1){
				if(seenBeggar == true){
					cout << "You've already talked with the beggar. Choose another option.";
				}
				else{
					int beggarValue = 0;
					cout << plot.text[85];
					cin >> beggarValue;
					if(beggarValue == 0){
						cout << "\"Ok. Thank you for your time anyway.\"";
					}
					else if(beggarValue == 27){
						cout<<"I see. Well then, I've heard that the king isn't a fan of the democratic processes\ngoing on in this town. There has been some serious conspiracy surrounding him.\nHave a nice day.";
					}
					else{
						cout << "\"Thank you so much. I wish you the best of luck in all that you do.\"";
					}
					seenBeggar = true;
				}
			}
			if(pChoice == 2){
				cout << plot.text[86];
				pChoice = 0;
						Store *s = new Store(*character);
						while(s->openStore()); //new store interactions
			}
			if(pChoice == 3){
				cout << plot.text[89];
			}
		}

	}
	case (4): {
		save=4;
		cout<<plot.text[90];
		cout<<plot.text[91];
		getFileContents("FireMage.txt");
		mon = Monster(400,50,40,"Fire Mage");//fight fire mage
		battRes=character->battle(mon);
		if (battRes==2) {
					if (!Death(character)) {
						save = 0;
					}
					break;
				}
		character->incGold(700);
		cout<<plot.text[92];
		cout<<plot.text[93];
		cout<<plot.text[94];
		pChoice = input(2,character);
		if (pChoice==1) {
			cout<<plot.text[95];
		}
		if (pChoice==2) {
			cout<<plot.text[96];
		}
		getFileContents("IceMage.txt");
		mon = Monster(400,60,40,"Ice Mage");//fight ice mage
		battRes=character->battle(mon);
		if (battRes==2) {
					if (!Death(character)) {
						save = 0;
					}
					break;
				}
		character->incGold(700);
		cout<<plot.text[97];
		pChoice=input(2,character);
		if ((pChoice==1&&chance(50))||pChoice==2) {
			cout<<plot.text[98];
			getFileContents("StormMage.txt");
			mon = Monster(400,70,40,"Storm Mage");//fight storm mage
			battRes=character->battle(mon);
			if (battRes==2) {
					if (!Death(character)) {
						save = 0;
					}
					break;
				}
		}
		character->incGold(700);
		cout<<plot.text[99];
		cout<<plot.text[100];
		pChoice=input(2,character);
		if (pChoice==1) {
			Store *s = new Store(*character);
			while(s->openStore());
		}
		if (pChoice==2) {
			cout<<"Good luck! We hope you'll be able to make it out of this alive.";
		}
		cout<<plot.text[101];
		pChoice=input(2,character);
		if (pChoice==1) {
			cout<<plot.text[102];
			pChoice=input(3,character);
			if (pChoice==1) {
				cout<<plot.text[103];
			}
			if (pChoice==2) {
				cout<<"I understand but I hope I can rely on you when the time comes";
			}
			if (pChoice==3) {
				cout<<"That's disappointing to hear but I hope you will consider changing your mind. Good luck.";
			}
			cout<<"The man departs leaving you to start the trek up the mountain to the nest of the dragon";
			cout<<plot.text[104];
			pChoice=0;
			while (pChoice!=1) {
				pChoice=input(2,character);
				if (pChoice==2) {
					cout<<plot.text[105];
				}
			}
			cout<<plot.text[106];
			getFileContents("Dragon.txt");
			mon = Monster(2000,80,0,"Dragon");//fight dragon
			battRes=character->battle(mon);
			if (battRes==2) {
					if (!Death(character)) {
						save = 0;
					}
					break;
				}
			cout<<plot.text[107];
			cout<<plot.text[108];
			pChoice = input(2,character);
			if (pChoice==1) {
				cout<<plot.text[109];
				helped++;
			}
			if (pChoice==2) {
				cout<<plot.text[110];
			}
			cout<<plot.text[111];
			cout<<plot.text[112];
			pChoice=input(2,character);
			if (helped==7) {
				cout<<plot.text[113];
				cout<<plot.text[114];
				getFileContents("King.txt");
				mon = Monster(1,0,0,"King");//fight king
				battRes=character->battle(mon);
				cout<<plot.text[115];
				cout<<plot.text[116];
				cout<<plot.text[117];
				cout<<plot.text[118];
				character->incGold(20000);
				pChoice=input(2,character);
				if (pChoice==1){
					cout<<plot.text[119];
				}
				if (pChoice==2){
					cout<<plot.text[120];
				}
			}

			if (pChoice==1&&helped!=7) {
				cout<<plot.text[121];
				character->incGold(10000);
			}
			if (pChoice==2&&helped!=7) {
				cout<<plot.text[122];
				getFileContents("Guards.txt");
				mon = Monster(300,50,0,"Guards");//fight guards
				battRes=character->battle(mon);
				if (battRes==2) {
						if (!Death(character)) {
							save = 0;
						}
						break;
					}
				cout<<plot.text[123];
				cout<<plot.text[124];
				character->incGold(10000);
			}
		}
		end=true;
	}
	case 5: { //used for end of game and demo mode
		pChoice=0;
		while (pChoice!=1) {
			cout<<"\n1: Quit\n2: Fight\n3: Use store\n";
			pChoice=input(3, character);
			if (pChoice==1) {
				return 0;
			}
			if (pChoice==2) {
				getFileContents("Goblins.txt");
				mon = Monster(100,100,100,"Monster");//fight random monster
				battRes=character->battle(mon);
				if (battRes==2) {
						if (!Death(character)) {
							save = 0;
						}
						break;
					}
			}
			if (pChoice==3) {
				Store *s = new Store(*character);
				while(s->openStore());
			}
	}
	}
}
}
return 0;
	}
