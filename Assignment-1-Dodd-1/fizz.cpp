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

    fizz::fizz(){
        limit = 100;
    }
   void fizz::Run(){
       cout << endl;
    for(int i = 1; i <= limit; i++){
        if(i % 5 == 0 && i % 3 == 0){
            cout << "FizzBuzz\n";
        } else if(i % 5 == 0){
            cout << "Buzz\n";
        } else if(i % 3 == 0){
            cout << "Fizz\n";
        } else{
            cout << i << endl;
        }
    }
}
    void fizz::SetLimit(int limitInput){
    limit = (limitInput == '\0' || limitInput <= 0) ? 100 : limitInput;
}

