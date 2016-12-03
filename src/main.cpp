int main () {
	//do save point stuff
	save = 1;
	bool done1 = 0;
	bool done2 = 0;
	int pChoice = 0;
	int helped = 0;
	bool end = false;
	bool found = false;
  	bool leftRoom = false;
    	bool rightRoom = false;
    	bool seenBeggar = false;
	string pResponse = "";
	Store s;
	
	bool chance(int luck) {
 		int v1 = rand() * 100;
  		if (v1 < luck) {
    			return true;
  		}
  		else return false;
		}
	
	switch (save) {
		Character hero = new Character;
		
		case (1): {
			cout << plot.text[0] << plot.text[1];
       			cin >> pChoice;

        		while(pChoice != 1 && pChoice != 3){

            		cout << plot.text[2];
           		cin >> pChoice;

            		if(pChoice == 1){
                		cout << plot.text[3];
                		Character.incGold(500);
            		}
            if(pChoice == 2){
                cout << plot.text[4];
            }
            if(pChoice == 3){

                if (chance(50) == true){
                    cout << plot.text[5];
                    Character.incGold(750);
                }
                if (chance(50) == false){
                    cout << plot.text[6]
                    Character.incGold(500);
                }
            }
            else{
                cout << "Please enter an option from the menu."
            }
        }

        cout << plot.text[7];
        while (pChoice != 2){

            cout.text[8];
            cin >> pChoice;

            if(pChoice == 1){
                cout << plot.text[9];
                Character.decGold(1);
                }
            if(pChoice == 2){
                cout << plot.text[10];
                cin >> pChoice;
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
            else{
                cout << "Please enter an option from the menu.";
            }
        }

        cout << plot.text[15];
        cout << plot.text[16];
        cin >> pChoice;

        if(pChoice == 1){
            //character.battle(wolves)
            //helped++;
            //level up
        }
        if(pChoice == 2){
        }

        cout << plot.text[17];
        cout << plot.text[18];
        cin >> pChoice;

        if(pChoice == 1){
            cout << plot.text [19];
            character.incGold(20);
            cout << plot.text[20];
            cin >> pChoice;

            if(pChoice == 1){
                cout << plot.text[22];
                cout << plot.text[23];
                cin >> pChoice;

                if(pChoice == 1){
                    //character.battle(bandits)
                    cout << plot.text[24];
                    Character.incGold(150);
                    helped++;
                    //level up
                }
                if(pChoice == 2){
                    if(chance(40) == true){
                        //character.battle(bandits)
                        cout << plot.text[24];
                        Character.incGold(150);
                        helped++;
                        //level up
                    }
                    if(chance(40) == false){
                        //character.battle(bandits)
                        helped++;
                    }
                }
                if(pChoice == 3){
                    if(chance(60) == true){
                        cout << plot.text[25];
                    }
                    if(chance(60) == false){
                        //character.battle(bandits)
                        cout << plot.text[24];
                        helped++;
                    }
                }

            }

            if(pChoice == 2){
                cout << plot.text[21];
            }
        }
        cout << plot.text[26];
		}
/////////////////////////////////////////////////////////////			
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
//////////////////////////////////////////////////////////////////////////
		case (3): {
			pChoice = 0;
        cout << plot.text[54];
        while(pChoice != 1 || 2){
            cout << plot.text[55];
            cin >> pChoice;

            if(pChoice == 1){

            }
            if(pChoice == 2){
                cout << plot.text[57];
                cin >> pChoice;
                if(pChoice == 1){
                    cout << plot.text[59];
                    cin >> pChoice;
                    if(pChoice == 1){
                        if(chance(50) == true){
                            cout << plot.text[60];
                        }
                        if(chance(50) == false){
                            cout << plot.text[61];
                            //-5% health
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
        cin >> pChoice;

        if(pChoice == 1){
            cout << plot.text[64];
        }
        if(pChoice == 2){
            cout << plot.text[65];
        }

        cout << plot.text[66] << plot.text[67] << plot.text[68];
        cout << plot.text[69];
        cin >> pChoice;
        if(pChoice == 1){
            cout << plot.text[70];
        }
        if(pChoice == 2){
            cout << plot.text[71];
        }
        if(pChoice == 3){
            cout << plot.text[72];

            cout << plot.text[73];
            cin >> pChoice;

            //Choices 1 & 2 lead to same point
            if(pChoice == 1 || pChoice == 2){
            if(pChoice == 1){
                cout << plot.text[75];
                //character.battle(thieves)
            }
            if(pChoice == 2){
                cout << plot.text[76];
                cin >> pChoice;
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
                        cout << "You have already been here. Choose another option."
                    }
                    else{
                        cout << plot.text[80];
                        Character.incGold(400);
                        leftRoom = true;
                    }
                }
                if(pChoice == 2){
                    if(rightRoom == true){
                        cout << "You have already been here. Choose another option."
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
            cin >> pChoice;

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
                        //CONSPIRACY
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
                    cin >> pChoice;
                    if(pChoice == 1){
                        //open store
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
		
	}


}
