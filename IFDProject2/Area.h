#include <string>
#include <iostream>
#include "Item.h"
#include "ull.h"

using namespace std;

class Area{
  public:
    void setDescription (string desc){
    	description = desc;
    }
    void setGoal(bool g){
	goal = g;		
    }
    void setID(bool id){
	instadeath = id;		
    }
    string getDescription(){
    	return description;
    }
    bool getID(){
    	return instadeath;
    }
    bool getGoal(){
	return goal;
    }
    void displayArea(){
	cout<<description<<endl;		
    }
    void search(){
        bool found = false;
        nodeType<Item*>* current = items.getFirst();
        nodeType<Item*>* next = current;
        nodeType<Item*>* temp;
        if(current == NULL){
            cout <<"There are no items in this area\n";
        }
        if(next != NULL){
            if(current->info->GetSR() == ){
                
            }
            temp = next;
            next = next->link;
            current = temp;

        }
        
    }
  private:
    uLList<Item*> items;
    string description;
    bool instadeath;
    bool goal;	
};
