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

//_________________________________________________ return the BigReal size
int BigReal :: size(){
    return integer.size() + fraction.size() + 2;
}

//_________________________________________________ return the BigReal sign
int BigReal :: sign(){
    if(BigRealSign == '+') return 1;
    return -1;
}

//_________________________________________________ overloading operator <
bool BigReal :: operator< (BigReal anotherReal){
    bool lessThan{false}, graterThan{false};
    // if they don't have the same sign the positive will be the bigger
    if(this -> BigRealSign == '+' && anotherReal.BigRealSign == '-') return false;
    else if(this -> BigRealSign == '-' && anotherReal.BigRealSign == '+') return true;

    // if they have the same sign look up what is it
    // and then compare with the appropriate way
    //_______________________________________________________________________________

    if(this -> integer.size() < anotherReal.integer.size()) lessThan = true, graterThan = false;
    else{
        for(unsigned long long i = integer.size() - 1; i > 0; i--){
            if(this -> integer[i] > anotherReal.integer[i]){
                graterThan = true;
                lessThan = false;
                break;
            }
            else if(this -> integer[i] < anotherReal.integer[i]){
                lessThan = true;
                graterThan = false;
                break;
            }
        }
    }

    // if the integer part is equal check the fraction part
    if(!lessThan && !graterThan){
        unsigned long long lowSiz = this->fraction.size();
        if (lowSiz > anotherReal.fraction.size()) lowSiz = anotherReal.fraction.size();
        for (unsigned long long i = lowSiz - 1; i > 0; i--) {
            if (this->fraction[i] > anotherReal.fraction[i]){
                graterThan = true;
                lessThan = false;
                break;
            }

            else if (this->fraction[i] < anotherReal.fraction[i]){
                lessThan = true;
                graterThan = false;
                break;
            }
        }
        if ((this->fraction.size() < anotherReal.fraction.size()) && !lessThan && !graterThan) {
            lessThan = true;
            graterThan = false;
        }
    }
    if((lessThan && BigRealSign == '+') || (graterThan && BigRealSign == '-')) return true;
    else return  false;
}

//_________________________________________________ overloading operator >
bool BigReal :: operator> (BigReal anotherReal){
    bool lessThan{false}, graterThan{false};
    // if they don't have the same sign the positive will be the bigger
    if(this -> BigRealSign == '+' && anotherReal.BigRealSign == '-') return true;
    else if(this -> BigRealSign == '-' && anotherReal.BigRealSign == '+') return false;

    // if they have the same sign look up what is it
    // and then compare with the appropriate way
    //_______________________________________________________________________________

    if(this -> integer.size() < anotherReal.integer.size()) lessThan = true, graterThan = false;
    else{
        for(unsigned long long i = integer.size() - 1; i > 0; i--){
            if(this -> integer[i] > anotherReal.integer[i]){
                graterThan = true;
                lessThan = false;
                break;
            }
            else if(this -> integer[i] < anotherReal.integer[i]){
                lessThan = true;
                graterThan = false;
                break;
            }
        }
    }

    // if the integer part is equal check the fraction part
    if(!lessThan && !graterThan){
        unsigned long long lowSiz = this->fraction.size();
        if (lowSiz > anotherReal.fraction.size()) lowSiz = anotherReal.fraction.size();
        for (unsigned long long i = lowSiz - 1; i > 0; i--) {
            if (this->fraction[i] > anotherReal.fraction[i]){
                graterThan = true;
                lessThan = false;
                break;
            }

            else if (this->fraction[i] < anotherReal.fraction[i]){
                lessThan = true;
                graterThan = false;
                break;
            }
        }
        if ((this->fraction.size() > anotherReal.fraction.size()) && !lessThan && !graterThan) {
            graterThan = true;
        }
    }
    if((graterThan && BigRealSign == '+') || (lessThan && BigRealSign == '-')) return true;
    else return  false;
}

//_________________________________________________ overloading operator ==
bool BigReal :: operator== (const BigReal& anotherReal){
    // if num >! num2 && num <! num2 that means num == num2
    if((*this > anotherReal) || (*this < anotherReal)) return false;
    return true;

}

//_________________________________________________ overloading operator +
BigReal BigReal::operator+(const BigReal& other){
    BigReal answer;
    int carry = 0;

    // Add fractions
    int maxSize = std::max(fraction.size(), other.fraction.size());
    for (int i = 0; i < maxSize; ++i) {
        int num1 = (i < fraction.size()) ? fraction[i] : 0;
        int num2 = (i < other.fraction.size()) ? other.fraction[i] : 0;
        int sum = num1 + num2 + carry;
        carry = sum / 10;
        answer.fraction.push_back(sum % 10);
    }

    // Add integers
    maxSize = std::max(integer.size(), other.integer.size());
    for (int i = 0; i < maxSize; ++i) {
        int num1 = (i < integer.size()) ? integer[i] : 0;
        int num2 = (i < other.integer.size()) ? other.integer[i] : 0;
        int sum = num1 + num2 + carry;
        carry = sum / 10;
        answer.integer.push_back(sum % 10);
    }

    // If there is a carry after adding integers, add it to the answer
    if (carry > 0) {
        answer.integer.push_back(carry);
    }

    // Set the sign of the answer
    answer.BigRealSign = BigRealSign;

    return answer;
}
//_________________________________________________ overloading operator -
BigReal BigReal::operator- (BigReal& other) {
    BigReal answer, small, big;
    unsigned long long siz = 0;
    int borrow = 0;

    // Determine the larger and smaller numbers
    if (*this > other || *this == other) {
        big = *this;
        small = other;
    } else {
        big = other;
        small = *this;
        answer.BigRealSign = '-';  // Set the sign of the answer to negative
    }

    // Subtract integers
    siz = max(big.integer.size(), small.integer.size());
    for(unsigned long long i = 0; i < siz; i++){
        int digitBig = i < big.integer.size() ? big.integer[i] : 0;
        int digitSmall = i < small.integer.size() ? small.integer[i] : 0;

        int diff = digitBig - digitSmall - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        answer.integer.push_back(diff);
    }

    // Subtract fractions
    siz = std::max(big.fraction.size(), small.fraction.size());
    for(unsigned long long i = 0; i < siz; i++){
        int digitBig = i < big.fraction.size() ? big.fraction[i] : 0;
        int digitSmall = i < small.fraction.size() ? small.fraction[i] : 0;

        int diff = digitBig - digitSmall - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        answer.fraction.push_back(diff);
    }

    // Remove leading zeros from the answer's integer part
    while (!answer.integer.empty() && answer.integer.back() == 0) {
        answer.integer.pop_back();
    }

    // If the answer is zero, set the sign to positive
    if (answer.integer.empty() && answer.fraction.empty()) {
        answer.BigRealSign = '+';
    }

    return answer;
}