//Ibrahim Hassan Mohammed Hassan - 20210002 - ibrahimhassannamr@gmail.com
// Abdulmalik Mahmoud Hussein - 20220205 - abdelmaleka011@gamil.com
// Islam Mohammed Ahmed Ali - 20220059 - islmslm999@gmail.com

#ifndef BIGREAL_BIGREAL_H
#define BIGREAL_BIGREAL_H
#include <iostream>
#include <svector>
using namespace std;
class BigReal{
private:
    vector <int> integer; // to save integer part
    vector <int> fraction; // to save fraction part
    unsigned long long dotIndex; // to save the position of dot
    char BigRealSign; // to save the BigReal sign
    bool isValidReal (string realNumber); // check if it's a valid number
public:
    BigReal(); // Default constructor
    BigReal(const string& realNumber); // Initialize from string
    BigReal(const BigReal& other); // Copy constructor
    BigReal& operator=(BigReal& other); // Assignment operator
    BigReal operator+ (const BigReal& other); // operator +
    BigReal operator- (BigReal& other); // operator -
    void setNum(string realNumber); // change BigReal value
    int size(); // return BigReal size
    int sign(); // return BigReal sign
    bool operator< (BigReal anotherReal); // < overloading
    bool operator> (BigReal anotherReal); // > overloading
    bool operator== (const BigReal& anotherReal); // == overloading
    friend ostream& operator << (ostream& out, BigReal num); // make the fn operator << friend fn
};
#endif //BIGREAL_BIGREAL_H
