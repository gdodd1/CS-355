#include<iostream>
#include "Map.h"
#include "Player.h"
using namespace std;

class MapV2 : public Map{
    private:
vector<Item*> itemVec;
    public:
MapV2(){
			ifderr = false;
			parser.tokenIt();

			nextToken = parser.getNext();

			if(nextToken == "<game>"){
				parser.eatToken();
				nextToken = parser.getNext();
				while(nextToken != "</game>"){  //consider what happens when run out of tokens && not error state
					if(nextToken == "<area>"){
						parser.eatToken();
						nextToken = parser.getNext();
						makeArea();
					}
					else if(nextToken == "<links>"){
						parser.eatToken();
						nextToken = parser.getNext();
						makeLinks();
					}
                    else if(nextToken == "<item>"){
						parser.eatToken();
						nextToken = parser.getNext();
						makeItem();
					}
					else{
						cout<<"Parse Error Location 1"<<endl;
						ifderr = true;
						break;
					}
					parser.eatToken();
					nextToken = parser.getNext();
				}// while !</game>

				if(ifderr){
					cout<<" :: ERROR :: IF Document Formatting Error"<<endl;
					cout<<"Game Loading Failed"<<endl;
					cout<<"General Area of Parsing Failure:"<<endl;
					cout<<"-------------------------------------"<<endl;
					cout<<nextToken<<endl;
					parser.eatToken();
					nextToken = parser.getNext();
					cout<<nextToken<<endl;
					parser.eatToken();
					nextToken = parser.getNext();
					cout<<nextToken<<endl;
					parser.eatToken();
					nextToken = parser.getNext();
					cout<<nextToken<<endl;
					cout<<"-------------------------------------"<<endl;
					return;
				}
				//cout<<"::Found </game>::"<<endl;
			}
			else{
				cout<<" :: ERROR :: No \"<game>\" tag found."<<endl;
				cout<<"Game Loading Failed"<<endl;
			}

			//link up areas
			linkLinks();
			InsertItems();

		//constructor
}

void makeItem(){
			string name, description;
            int room;
			string xstr;

			Item* tempItemPtr = new Item;

			while(nextToken != "</item>"){
				if(nextToken == "<desc>"){
					parser.eatToken();
					nextToken = parser.getNext();
					
					tempItemPtr->setDesc(nextToken);
				}
				else if(nextToken == "<name>"){
					parser.eatToken();
					nextToken = parser.getNext();
					tempItemPtr->setName(nextToken);
				}
				else if(nextToken == "<star>"){
					parser.eatToken();
					nextToken = parser.getNext();
					tempItemPtr->setSR(stoi(nextToken));
				}
				else if(nextToken == "</desc>" || nextToken == "</star>"){
				  //do nothing
				}
				else{
					cout<<"Parse Error Location 2"<<endl;
					ifderr = true;
					break;
				}

				parser.eatToken();
				nextToken = parser.getNext();
			}//while !</item>

			//add item to vector
			itemVec.push_back(tempItemPtr);

}

void InsertItems(){

	for(int i = 0; i < itemVec.size(); i++){
		areasVec[itemVec[i]->getSR() - 1]->info.items.insertLast(itemVec[i - 1]); 
	}

}

void resetItems(){
	
	for(int i = 0; i < itemVec.size(); i++){
		areasVec[itemVec[i]->getSR() - 1]->info.items.insertLast(itemVec[i - 1]); 
	}
}

friend ostream& operator<<(ostream& os, MapV2& map){
			os<<"******************************************************************"<<endl;
			os<<"CHEATING!!!! Printing the set of areas and connections on the map."<<endl;
			os<<"******************************************************************"<<endl;
			for(int i=0; i<map.areasVec.size(); i++){
				os<<"This is area: "<<i+1<<endl;
				os<<map.areasVec[i]->info.getDescription()<<endl;
				if(map.areasVec[i]->info.getID() == 1){
					os<<"Area is INSTADEATH."<<endl;
				}
				if(map.areasVec[i]->info.getGoal() == 1){
					os<<"Area is GOAL."<<endl;
				}
				os<<"Connections:"<<endl;
				os<<"\t u: Area #"<<map.reverseLookUp(map.areasVec[i]->u)<<endl;
				os<<"\t d: Area #"<<map.reverseLookUp(map.areasVec[i]->d)<<endl;
				os<<"\t l: Area #"<<map.reverseLookUp(map.areasVec[i]->l)<<endl;
				os<<"\t r: Area #"<<map.reverseLookUp(map.areasVec[i]->r)<<endl;

				os<<"\nItems for area " << i << ": " << map.areasVec[i]->info.getDescription();
				bool printedItem = false;
				for(int itemIterator = 0; itemIterator < map.itemVec.size(); itemIterator++){
					if(map.areasVec[i]->info.items.search(map.itemVec[itemIterator])){

						os<< map.itemVec[itemIterator]->getName(); 
					}
				}
			}
			return os;
		}




};