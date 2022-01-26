/*
Name: Garrett Dodd
Date: 26 January 2022
Due Date: 27 January 2022
Professor: Dr. Ray
Class: CS 355 - Data Structures and Algorithms
*/

#include <iostream>
#include "advancedCaeser.h"
using namespace std;

int main(){
    string input1, input2;

    cout << "Please enter two words seperated by spaces to be used in the cipher: ";
    cin >> input1 >> input2;

    cout << "\n\n***** USING INT CONSTRUCTOR - SHIFT VALUE: 8 *****\n\n";
    advancedCaeser c1(8);
    cout << "Word chosen: " << input1 << endl;
    cout << "Encrypted:\n" << c1.encrypt(input1) << endl;
    cout << "Decrypted:\n" << c1.decrypt(c1.encrypt(input1)) << endl;

    c1.print();

    cout << "\n\n***** DONE WITH C1 - INT CONSTRUCTOR *****\n\n";

    advancedCaeser c2;

    cout << "\n\n***** USING NO PARAMETER CONSTRUCTOR - SHIFT VALUE: 1 *****\n\n";

    cout << "Word chosen: " << input2 << endl;
    cout << "Encrypted: \n" << c2.encrypt(input2) << endl;
    cout << "Decrypted: \n" << c2.decrypt(c2.encrypt(input2)) << endl;

    c2.print();

    cout << "\n\n***** DONE WITH C2 - NO PARAMETER CONSTRUCTOR *****\n\n";

// Finally, write a main function that creates an instance of advancedCaesar 
// and tests all of its methods; including 
// it’s constructors, it’s print method, and encrypt and 
// decrypt (use cout statements to print the result of encrypt and decrypt)









}