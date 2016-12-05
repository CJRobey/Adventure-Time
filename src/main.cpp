bool chance(int luck) {

	if ((rand() * 100) < luck) {
		return true;
	}
	else return false;
}

string input(int choices) {
	string pChoice;
	while (true) {
		cin>>pChoice;
	if ((pChoice>=0&&pChoice<=choices)) {
		return pChoice; 	
	}
	cout<<"Please enter a valid choice:\n";

	}
}

bool Death() {
	cout<<"Do you want to continue?\n\t1:Yes\n\t2:No";
	string pChoice = input(2);
	if (pChoice==1) {
		return true;
	}
	if (pChoice==2) {
		return false;
	}
	
}


int main () {
	string pName;
	save = 1;
	bool done1 = 0;
	bool done2 = 0;
	int pChoice = 7;
	int helped = 0;
	startGold = 500;
	bool end = false;
	bool found = false;
	bool leftRoom = false;
	bool rightRoom = false;
	bool seenBeggar = false;
	bool moreGold = false;
	string pResponse = "";
	int battRes=7;
	Store s;
	Inventory i;
	Plot plot;	

	cout<<"What is your name?\n";
	cin>>pName;
	Character character = new Character(pName, i);
	if (pName=="ImaDev") {
		character.incOffense(50000);
		character.incGold(50000);
	}
	while (!end) {
	switch (save) {

	case (1): {
		cout << plot.text[0] << plot.text[1];

		while(pChoice != 1){

			cout << plot.text[2];
			pChoice=input(3);

			if(pChoice == 1){
				cout << plot.text[3];
				character.incGold(startGold);
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
		pChoice = input(2);
		

	if(pChoice == 1){
		cout << plot.text[9];
		character.decGold(1);
	}
	if(pChoice == 2){
		cout << plot.text[10];
		pChoice = input(2);
		if(pChoice == 1){
			cout << plot.text[11];
			character.incGold(50);
		}
		if(pChoice == 2){
			cout << plot.text[12];
		}
		cout << plot.text[13];
		//open and close store
		cout << plot.text[14];
	}
	
	}

	cout << plot.text[15];
	cout << plot.text[16];
	pChoice = input(2);

	if(pChoice == 1){
		battRes=character.battle(Monster(10,10,10,"Wolves");
			
		if (battRes==2) {
			if (!Death()) {
				save = 0;
			}
			break;
		}
		
	}
	

	cout << plot.text[17];
	cout << plot.text[18];
	pChoice = input(2);

	if(pChoice == 1){
		cout << plot.text [19];
		character.incGold(20);
		cout << plot.text[20];
		pChoice = input(2);

		if(pChoice == 1){
			cout << plot.text[22];
			cout << plot.text[23];
			pChoice = input(3);

			if(pChoice == 1){
				battRes = character.battle(Monster(20,20,20,"Bandits"));
				if (battRes==0) {
				cout << plot.text[24];
				Character.incGold(150);
				helped++;
				}
				if (battRes==1) {
					cout << plot.text[25];
				}
				}
		
			if(pChoice == 2){
				if(chance(40) == true){
					battRes = character.battle(Monster(15,15,20,"Bandits"));
					if (battRes==0) {
						cout << plot.text[24];
						Character.incGold(150);
						helped++;
					}
				if (battRes==1) {
					cout << plot.text[25];
				}
				}
				else {
					battRes = character.battle(Monster(20,20,20,"Bandits"));
					if (battRes==0) {
						cout << plot.text[24];
						Character.incGold(150);
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
					battRes = character.battle(Monster(20,20,20,"Bandits"));
					if (battRes==0) {
						cout << plot.text[24];
						Character.incGold(150);
						helped++;
					}
					if (battRes==1) {
						cout << plot.text[25];
					}
					
				}
			}

		}

		if(pChoice == 2){
			cout << plot.text[21];
		}
	}
	cout<<plot.text[26];
	}
	/////////////////////////////////////////////////////////////			
	case (2): {
		cout<<plot.text[27];
		pChoice = input(2);
		if (pChoice==1) {
			cout<<plot.text[28];
			character.incHealth(20);
			character.decHealth(10);
			battRes = character.battle(Monster(20,10,0,"Goblins"));
				if (battRes==2) {
					if (!Death()) {
						save = 0;
					}
					break;
				}
				
		}
		if (pChoice==2) {
			cout<<plot.text[29];
			battRes = character.battle(Monster(15,10,0,"Goblins"));
				if (battRes==2) {
					if (!Death()) {
						save = 0;
					}
					break;
				}
		}
		cout<<plot.text[30];
		cout<<plot.text[31];
		pChoice = input(2);
		while (pChoice!=2) {
			battRes = character.battle(Monster(20,10,0,"Goblins"));
				if (battRes==2) {
					if (!Death()) {
						save = 0;
					}
					break;
				}
			cout<<plot.text[30]<<plot.text[31]);
			pChoice = input(2);
		}
		cout<<plot.text[33];
		pChoice = input(2);
		if (pChoice==2) {
			cout<<plot.text[35];
			cout<<plot.text[36];
			int numCorrect=0;
			cin>>pResponse;
			if (pResponse=="Dark"||pResponse=="Darkness") {
				cout<<"Correct";
				numCorrect++;
			}
			else {cout<<"Incorrect";}
			cout<<plot.text[37];
			cin>>pResponse;
			if (pResponse=="Egg" {
					cout<<"Correct";
					numCorrect++;
			}
			else {cout<<"Incorrect";}
			cout<<plot.text[38];
			if (pResponse=="Time") {
				cout<<"Correct";
				numCorrect++;
			}
			else {cout<<"Incorrect";}
			if (numCorrect<2) {
				cout<<plot.text[39];
			}
			if (numcorrect>=2) {
				cout<<plot.text[40];
				cout<<plot.text[41];
			}
		}
		cout<<plot.text[42];
		pChoice = input(2);
		if (pChoice==2) {
			cout<<plot.text[43];
		}
		if (pChoice==1) {
			cout<<plot.text[44];
			while (pChoice!=2&&pChoice!=3) {
				cout<<plot.text[45];
				pChoice = input(4);
				if (pChoice==1) {
					s.openStore(); //new store interactions
				}
				if (pChoice==4) {
					cout<<plot.text[46];
				}
			}
			if (pChoice==2) {
				cout<<plot.text[47];
				cout<<plot.text[48];
				pChoice = input(2);
				if (pChoice==1) {
					s.openStore();
				}
			}
			if (pChoice==3) {
				cout<<plot.text[49];
				character.decHealth(10);
				battRes = character.battle(Monster(30,30,30,"Carriage Driver");
				if (battRes==2) {
					if (!Death()) {
						save = 0;
					}
					break;
				}
				
				if (battRes==0) {
					helped++;
					cout<<plot.text[50];
				pChoice = input(3);
				cout<<plot.text[51];
				cout<<plot.txt[52];
				pChoice = input(2);
					if (pChoice==1) {
						s.openStore(); //new store interactions
					}
				cout<<plot.text[53];
				}
			}


		}


	}
	//////////////////////////////////////////////////////////////////////////
	case (3): {
		pChoice = 0;
		cout << plot.text[54];
		while(pChoice != 1 || pChoice!=2){
			cout << plot.text[55];
			pChoice = input(2);

			
			if(pChoice == 2){
				cout << plot.text[57];
				pChoice = input(2);
				if(pChoice == 1){
					cout << plot.text[59];
					pChoice = input(2);
					if(pChoice == 1){
						if(chance(50) == true){
							cout << plot.text[60];
						}
						else{
							cout << plot.text[61];
							character.decHealth(5);
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
			if(pChoice == 3){
				cout << plot.text[56];
				found == true;
			}
			if(pChoice == 3 && found == true){
				cout << "You already investigated the bakery. Choose something else.";
			}
		}

		cout << plot.text[63];
		pChoice = input(2);

		if(pChoice == 1){
			cout << plot.text[64];
		}
		if(pChoice == 2){
			cout << plot.text[65];
		}

		cout << plot.text[66] << plot.text[67] << plot.text[68] << plot.text[69];
		pChoice = input(3);
		if(pChoice == 1){
			cout << plot.text[70];
		}
		if(pChoice == 2){
			cout << plot.text[71];
		}
		if(pChoice == 3){ //very very bad
			cout << plot.text[72];

			cout << plot.text[73];
			pChoice = input(3);

			//Choices 1 & 2 lead to same point
			if(pChoice == 1 || pChoice == 2){
				if(pChoice == 1){
					cout << plot.text[75];
					//character.battle(thieves)
				}
				if(pChoice == 2){
					cout << plot.text[76];
					pChoice = input(2);
					if(pChoice == 1){
						//character.battle(thieves) - surprise attack
					}
					if(pChoice == 2){
						cout << plot.text[77];
						//character.battle(thieves)
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
							Character.incGold(400);
							leftRoom = true;
						}
					}
					if(pChoice == 2){
						if(rightRoom == true){
							cout << "You have already been here. Choose another option.";
						}
						else{
							cout << plot.text[81];
							rightRoom = true;
						}
					}
					if(pChoice == 3){
						cout << plot.text[82];
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
			pChoice = input(3);

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
						cout<<"I see. Well then, I've heard that the king isn't a fan of the democratic processes\ngoing on in this town. There has been some serious conspiracy surrounding him.\nHave a nice day."
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
				while(pChoice != 2){
					cout << plot.text[87];
					pChoice = input(2);
					if(pChoice == 1){
						s.openStore; //new store interactions
					}
					if(pChoice == 2){
						cout << plot.text[88];
					}
				}
			}
			if(pChoice == 3){
				cout << plot.text[89];
			}
		}

	}
	case (4): {
		cout<<plot.text[90];
		cout<<plot.text[91];
		battRes=character.battle(Monster(60,40,0,"Fire Mage");
		if (battRes==2) {
					if (!Death()) {
						save = 0;
					}
					break;
				}
		cout<<plot.text[92];
		cout<<plot.text[93];
		cout<<plot.text[94];
		pChoice = input(2);
		if (pChoice==1) {
			cout<<plot.text[95];
		}
		if (pChoice==2) {
			cout<<plot.text[96];
		}
		battRes=character.battle(Monster(60,40,40,"Ice Mage");
		if (battRes==2) {
					if (!Death()) {
						save = 0;
					}
					break;
				}
		cout<<plot.text[97];
		pChoice=input(2);
		if ((pChoice==1&&chance(50))||pChoice==2) {
			cout<<plot.text[98];
			battRes=character.battle(Monster(60,40,40));
			if (battRes==2) {
					if (!Death()) {
						save = 0;
					}
					break;
				}
		}
		cout<<plot.text[99];
		cout<<plot.text[100];
		pChoice=input(2);
		if (pChoice==1) {
			s.openStore();
		}
		if (pChoice==2) {
			cout<<"Good luck! We hope you'll be able to make it out of this alive.";
		}
		cout<<plot.text[101];
		pChoice=input(2);
		if (pChoice==1) {
			cout<<plot.text[102];
			pChoice=input(3);
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
				pChoice=input(2);
				if (pChoice==2) {
					cout<<plot.text[105];
				}
			}
			cout<<plot.text[106];
			battRes=character.battle(Monster(100,100,0,"Dragon");
			if (battRes==2) {
					if (!Death()) {
						save = 0;
					}
					break;
				}
			cout<<plot.text[107];
			cout<<plot.text[108];
			pChoice = input(2);
			if (pChoice==1) {
				cout<<plot.text[109];
			}
			if (pChoice==2) {
				cout<<plot.text[110];
			}
			cout<<plot.text[111];
			cout<<plot.text[112];
			pChoice=input(2);
			if (helped==7) {
				cout<<plot.text[113];
				cout<<plot.text[114];
				cout<<plot.text[115];
				cout<<plot.text[116];
				cout<<plot.text[117];
				cout<<plot.text[118];
				character.incGold(20000);
				pChoice=input(2);
				if (pChoice==1){
					cout<<plot.text[119];
				}
				if (pChoice==2){
					cout<<plot.text[120];
				}
				
				
			}
			if (pChoice==1&&helped!=7) {
				cout<<plot.text[121];
				character.incGold(10000);
			}
			if (pChoice==2&&helped!=7) {
				cout<<plot.text[122];
				cout<<plot.text[123];
				cout<<plot.text[124];
				character.incGold(10000);
			}
		}
	}
	}

	}
