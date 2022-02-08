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

	void inventory(){
		Item* current = items.getFirst();
		Item* next = current.link;
		Item* temp = current;
		if(items == nullptr){
			cout << "No Items Are In Your Inventory.\n";
		}
		else{
			cout << "You Have The Following Items:\n";
			while(next != nullptr){
				cout << "\t" << items->info << endl;

				temp = next;
				current = next;
				next = current.link;
			};
		}
	}

	void take(){
		string itemInput;
		cout << "Take What Item? ";
		cin >> itemInput;

		


	}

		uLList<Item*> items;
  private:
		areaNode* currentLocation;
		areaNode* lastLocation;

};
