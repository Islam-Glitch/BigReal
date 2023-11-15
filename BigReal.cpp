#include "BigReal.h"

//___________________________________________isValidReal
bool BigReal :: isValidReal (string realNumber){
    int DotsNum{0};
    for(unsigned long long i{1}; i < realNumber.size(); i++){
        // loop on the string if u found anything other the dot and the numbers
        // or more than one dot return false
        if(((int)realNumber[i] >= 48 && (int)realNumber[i] <= 57) || realNumber[i] == '.'){
            if(realNumber[i] == '.') {
                dotIndex = i;
                DotsNum++;
                if(DotsNum > 1) return false;
            }
        }
        else return false;
        //_______________________________________________________
    }

    // if the user didn't add a sign and it's a valid number
    if((int)realNumber[0] >= 48 && (int)realNumber[0] <= 57 || realNumber[0] == '.') return true;
    if(realNumber[0] == '+' || realNumber[0] == '-') return true; // if the first index is sign
    return false;
}
