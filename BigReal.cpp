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

//___________________________________________default constructor
BigReal :: BigReal (){
    // make the number positive and equal 0.0 by default
    BigRealSign = '+';
    integer.push_back(0);
    fraction.push_back(0);
}

//_________________________________________________ parametrized constructor
BigReal :: BigReal(const string& realNumber){
    // first check if it's a valid number
    if(isValidReal(realNumber)){
        // take the sign if there otherwise make it + by default
        if(realNumber[0] == '+' || realNumber[0] == '-') BigRealSign = realNumber[0];
        else BigRealSign = '+';

        // fill the integer part tell the dot position
        for(unsigned long long i{dotIndex - 1};i > 0; i--){
            integer.push_back((int)realNumber[i] - 48);
        }

        // fill the fraction part tell the end
        unsigned long long siz = realNumber.size();
        for(unsigned long long i{siz - 1};i > dotIndex && (dotIndex != 0 || realNumber[0] == '.'); i--){
            fraction.push_back((int)realNumber[i] - 48);
        }

        // if the fraction part or the integer part is empty assign it with 0
        if(integer.empty()) integer.push_back(0);
        if(fraction.empty()) fraction.push_back(0);
    }

        // tell the user his number is not valid
    else{
        cout << "not valid number\n";
        this -> integer.push_back(0);
        this -> fraction.push_back(0);
    }
}

//_________________________________________________ copy constructor
BigReal :: BigReal(const BigReal& other){
    // take the sign copy
    this -> BigRealSign = other.BigRealSign;

    // then copy the integer part
    for(unsigned long long i{0}; i < other.integer.size(); i++)
        this -> integer.push_back(other.integer[i]);

    // then copy the fraction part
    for(unsigned long long i{0}; i < (other.fraction).size(); i++)
        this -> fraction.push_back(other.fraction[i]);

    // copy the position of the dot
    this -> dotIndex = other.dotIndex;
}
