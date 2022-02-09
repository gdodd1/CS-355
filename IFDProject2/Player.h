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

	void take(){
		string itemInput;
		cout << "Take What Item? ";
		cin >> itemInput;

        cout<<"Take\n";
        nodeType<Item*>* current = currentLocation->info.items.getFirst();
		if(current == nullptr){
			cout << "No Items Are In This Area.\n";
		}
		else{
		 	while(current != nullptr){
                if(current->info->getName() == itemInput){
                    cout<<"You have taken: "<<current->info->getName()<<endl;
					break;
				}
				current = current->link;
		 	}
			// adding into inventory
			items.insertLast(current);
		}
        cout<<"\nTake End\n";
	}

    void leave(){
        string lItem;
        cout<<"Leave what item? ";
        cin>>lItem;

        cout<<"Leave\n";
        searchIt(lItem);
    }

    void examine(){
        string item;
        cout<<"What examine? ";
        cin>>item;

        cout<<"Examine\n";
        searchIt(item);
    }

	uLList<Item*> items;
  private:
		areaNode* currentLocation;
		areaNode* lastLocation;

};
