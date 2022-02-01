#include <iostream>
using namespace std;

class Item{
    string name;
    string description;
    int SR;

    public:
        void SetName(string n){
            name = n;
        }
        void SetDescription(string d){
            description = d;
        }
        void SetSR(int r){
            SR = r;
        }
        string GetName(){
            return name;
        }
        string getDesc(){
            return description;
        }
        int GetSR(){
            return SR;
        }
        void DisplayName(){
            cout << name;
        }
        void DisplayDesc(){
            cout << description;
        }
        friend ostream& operator<<(ostream& os, Item& item){
            os << "Name: " << item.name << endl;
            os << "Description: " << item.description << endl;
            os << "Starting Room: " << item.SR << endl;
            return os;
        }
};
