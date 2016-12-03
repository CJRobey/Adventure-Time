int main () {
	//do save point stuff
	save = 1;
	bool done1 = 0;
	bool done2 = 0;
	int pChoice = 0;
	int helped = 0;
	bool end = false;
	string pResponse = "";
	Store s;
	
	switch (save) {
		Character hero = new Character;
		
		case (1): {
			
		}
		case (2): {
			cout<<plot.text[27];
			cin>>pChoice;
			if (pChoice==1) {
				cout<<plot.text[28];
				//TODO open fight on ambushing goblins
			}
			if (pChoice==1) {
				cout<<plot.text[29];
				//TODO open fight on goblins
			}
			cout<<plot.text[30];
			cout<<plot.text[31];
			cin>>pchoice;
			while (pChoice!=2) {
				//open fight on goblins
				cout<<plot.text[30]<<plot.text[31]);
				cin>>pChoice;
			}
			cout<<plot.text[33];
			cin>>pChoice;
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
				cin>>pChoice;
				if (pChoice==2) {
					cout<<plot.text[43];
				}
				if (pChoice==1) {
					cout<<plot.text[44];
					while (pChoice!=2&&pChoic!=3) {
						cout<<plot.text[45];
						cin>>pChoice;
						if (pChoice==1) {
							s.openStore();
						}
						if (pChoice==4) {
							cout<<plot.text[46];
						}
					}
					if (pChoice==2) {
						cout<<plot.text[47];
						cout<<plot.text[48];
						cin>>pChoice;
						if (pChoice==1) {
							s.openStore();
						}
					}
					if (pChoice==3) {
						cout<<plot.text[49];
						//open fight carriage driver
						cout<<plot.text[50];
						cin>>pChoice;
						cout<<plot.text[51];
						cout<<plot.txt[52];
						cin>>pChoice;
						if (pChoice==1) {
							s.openStore();
						}
						cout<<plot.text[53];
					}
					
					
				}
			
			
	}
		case (3): {
			
		}
		case (4): {
		
	}


}
