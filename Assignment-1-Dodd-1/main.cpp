/*
 Name: Garrett Dodd
 Date: 10 January 2022
 Assignment: Assignment 1 - FizzBuzz Generator Class
 Due Date: 12 January 2022
 Professor: Dr. Ray
 */

#include <iostream>
#include "fizz.h"
using namespace std;

void menu(){
    fizz fizzyBoy;
    char menuInput =  'Y';
    while(toupper(menuInput) == 'Y'){
        cout << "\n----- FizzBuzz -----\n";
        cout << "------- MENU -------\n";
        cout << "1. Set Limit\n";
        cout << "2. Run\n";
        cout << "3. Clear screen\n";
        cout << "4. Exit\n";
        cout << "Input which option you'd like: ";
        int switchInput;
        cin >> switchInput;
        switch (switchInput){
            case 1:     cout << "\n\nWhat would you like to set the limit to? ";
                        int num;   cin >> num;
                        fizzyBoy.SetLimit(num);
                        cout << "Would you like to run with this input? (Y/N) ";
                        char caseChoice;
                        cin >> caseChoice;
                        if(toupper(caseChoice) == 'Y'){fizzyBoy.Run();}else{break;}
                        cout << "\n\n*** Go again? (Y/N) ***    ";
                        cin >> menuInput;
                        break;
            case 2:        cout << "\n\n***** Running *****\n\n";
                        fizzyBoy.Run();
                        cout << "\n\n ***** Finished Running ******\n\n";
                        cout << "\n\n*** Go again? (Y/N) ***    ";
                        cin >> menuInput;
                        break;
            case 3:     for(int o = 0; o < 50; o++){
                            cout << "\n";
                        }
                        break;
            case 4:     exit(0);
                        break;
            default:     cout << "\n\n ***** ERROR: INVALID INPUT *****\n\n";
                        continue;
            }
                    
    }
}

int main(){
    menu();
    return 0;
    
}
