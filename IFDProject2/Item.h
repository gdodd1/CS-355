#ifndef ITEM_H
#define ITEM_H

#include <iostream>
using namespace std;

class Item{
    string name;
    string description;
    int SR;

    public:
        void setName(string n){
            name = n;
        }
        void setDesc(string d){
            description = d;
        }
        void setSR(int r){
            SR = r;
        }
        string getName(){
            return name;
        }
        string getDesc(){
            return description;
        }
        int getSR(){
            return SR;
        }
        void displayName(){
            cout << name << endl;
        }
        void displayDesc(){
            cout << description;
        }
        friend ostream& operator<<(ostream& os, Item& item){
            os << "Name: " << item.name << endl;
            os << "Description: " << item.description << endl;
            os << "Starting Room: " << item.SR << endl;
            return os;
        }
};
#endif