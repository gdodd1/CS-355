#ifndef PLAYER_H
#define PLAYER_H



class Player{
  public:
    Player(){
		lastLocation = NULL;
		currentLocation = NULL;
	}

	void setCurrent(areaNode* loc){
        lastLocation = currentLocation;
		currentLocation = loc;
	}

	bool playerMoved(){
		return !(lastLocation == currentLocation);
	}
	areaNode* getCurrent(){
		return currentLocation;
	}

	//isGameOver should return: 0 for continue, 1 for win, 2 for lose
	int isGameOver(){
		if (currentLocation->info.getID() == 1){
			return 2;
		}
		else if(currentLocation->info.getGoal() == 1){
			return 1;
		}
		else if(currentLocation->info.getID() == 0 && currentLocation->info.getGoal() == 0){
			return 0;
		}
		else{
			return 0;
		}
	}

    nodeType<Item*>* searchIt(string itemInput){
        nodeType<Item*>* current = items.getFirst();
		if(current == nullptr){
			cout << "No Items Are In This Area.\n";
		}
		else{
		 	cout << "You Have The Following Items:\n";
		 	while(current != nullptr){
		 		cout << "\t" << current->info->getName() << endl;
                if(current->info->getName() == itemInput){
                    cout<<"founded "<<current->info->getName()<<endl;
                    return current;
                }
				current = current->link;
		 	}
		}
        return nullptr;
    }

	void inventory(){
		nodeType<Item*>* current = items.getFirst();
		if(current == nullptr){
			cout << "No Items Are In Your Inventory.\n";
		}
		else{
		 	cout << "You Have The Following Items:\n";
		 	while(current != nullptr){
		 		cout << "\t" << current->info->getName() << endl;
				current = current->link;
		 	}
		}
	}
	//Garrett
	void take(){
		string itemInput;
		cout << "Take what item? ";
		getline(cin, itemInput);
		bool found = false;
		nodeType<Item*>* current = currentLocation->info.items.getFirst();

		if (current == nullptr)
			cout << "No items are in this area to take\n";
		else{
			while(current != nullptr){
				if (current->info->getName() == itemInput){
					cout << "You have taken: " << current->info->getName() << endl;
					items.insertLast(current->info);
					currentLocation->info.items.deleteNode(current->info);
					found = true;
					break;
				}
				current = current->link;
			}
			if(!found){
				cout << "No item by that name here.\n";
			}
		}

	}
	//Garrett
    void leave(){
		bool found = false;
        string lItem;
        cout<<"Leave what item? ";
        getline(cin, lItem);

		nodeType<Item*>* current = items.getFirst();
		if(current == nullptr){
			cout << "\nYou have no items in your Inventory\n";
		}
		else{
			//Iterates through ull and searches for the item with the name that's inputted
		 	while(current != nullptr){
				 //compares input to the name of the current item name of the iteration in the Player::items ull
                if(current->info->getName() == lItem){
                    cout<<"You have dropped: "<<current->info->getName()<<endl;
					items.deleteNode(current->info);
					currentLocation->info.items.insertFirst(current->info);
					found = true;
				}
				current = current->link;
		 	}
			 //checks if item is found, and if not prints no item found
			if (found == false){
				cout << "\nNo item by that name in your inventory.\n";
			}
		}
    }
	//Garrett
    void examine(){
		bool found = false;
        string item;
        cout<<"Examine what item?  ";
        getline(cin, item);

        nodeType<Item*>* current = items.getFirst();
		if(current == nullptr){
			cout << "\nYou have no items in your Inventory\n";
		}
		else{
			//Iterates through ull and searches for the item with the name that's inputted
		 	while(current != nullptr){
				 //compares input to the name of the current item name of the iteration in the Player::items ull
                if(current->info->getName() == item){
                    cout << current->info->getDesc() << endl;
					found = true;
				}
				current = current->link;
		 	}
			 //checks if item is found, and if not prints no item found
			if (found == false){
				cout << "\nNo item by that name in your inventory.\n";
			}
		}
    }

	uLList<Item*> items;
  private:
		areaNode* currentLocation;
		areaNode* lastLocation;

};

#endif