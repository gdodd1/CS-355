#ifndef fizz_h
#define fizz_h

/*
 Name: Garrett Dodd
 Date: 10 January 2022
 Assignment: Assignment 1 - FizzBuzz Generator Class
 Due Date: 12 January 2022
 Professor: Dr. Ray
 */

#include <iostream>

using namespace std;

class fizz{
    int limit;
public:
    fizz();
    void Run();
    void SetLimit(int limitInput);
};



#endif /* fizz_h */
