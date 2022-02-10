#include "areaNode.h"

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
		bool found = false;
		string itemInput;
		cout << "Take What Item? ";
		getline(cin, itemInput);

        cout<<"Take\n";
        nodeType<Item*>* current = currentLocation->info.items.getFirst();
		cout << "\n*** Current set *** \n";
		
		if(current == nullptr){
			cout << "No Items Are In This Area.\n";
		}
		else{
			//Iterates through ull and searches for the item with the name that's inputted
		 	while(current != nullptr){
				 cout << "\n\n ***In while loop ***\n\n";
				 //compares input to the name of the current item name of the iteration in the Player::items ull
				cout << "\n\n***if start ***\n\n";
                if(current->info->getName() == itemInput){

					cout << "\n\n***Iterated***\n\n";

                    cout<<"You have taken: "<<current->info->getName()<<endl;
					cout << "\n\n*** insert try ***\n\n";
					items.insertLast(current->info);
					cout << "\n\n***Item inserted into inventory***\n\n";
					currentLocation->info.items.deleteNode(current->info);
					cout << "\n\n***Node deleted from Area::items***\n\n";
					found = true;
				}
				else{
				current = current->link;
		 		cout << "\n\n***Current set to current->link***\n\n";
				}
				
				 //cout << "\n\n***Name Changed***\n\n";
			 }
			 //checks if item is found, and if not prints no item found
			if (found == false){
				cout << "No item by that name found here.\n";
			}
		}
        cout<<"\n\nTake End\n\n";
	}
	//Garrett
    void leave(){
		bool found = false;
        string lItem;
        cout<<"Leave what item? ";
        getline(cin, lItem);

		nodeType<Item*>* current = items.getFirst();
		if(current == nullptr){
			cout << "/nYou have no items in your Inventory\n";
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

        cout<<"Leave done\n";
        
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