#include <iostream>
#include "caesarCipher.h"
using namespace std;

class advancedCaeser : public caesarCipher{
private:
    char shiftedAlphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
public:
    advancedCaeser(){
        shiftValue = 1;

        for(int i=0;i<26;i++){
			if (shiftedAlphabet[i] >= 97 && shiftedAlphabet[i] <= 122){
				if (shiftedAlphabet[i]+shiftValue > 122){ 
					shiftedAlphabet[i]=122-(shiftedAlphabet[i]%97);	
				}
				else{
					shiftedAlphabet[i]+=shiftValue;
				}		
			}
		}

    }
    advancedCaeser(int n){
        shiftValue = n;

        for(int i=0;i<26;i++){
			if (shiftedAlphabet[i] >= 97 && shiftedAlphabet[i] <= 122){
				if (shiftedAlphabet[i]+shiftValue > 122){ 
					shiftedAlphabet[i]=122-(shiftedAlphabet[i]%97);	
				}
				else{
					shiftedAlphabet[i]+=shiftValue;
				}		
			}
		}

    }

    void print(){
        cout << "Shift value: \n" << shiftValue << "\nShifted alphabet::\n";
        for(int i = 0; i < 26; i++){
            cout << shiftedAlphabet[i];
        }
    }



};  