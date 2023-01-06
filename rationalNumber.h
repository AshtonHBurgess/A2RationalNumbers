//
// Created by w0465511 on 2022-11-15.
//

#ifndef A3RATIONAL_RATIONALNUMBER_H
#define A3RATIONAL_RATIONALNUMBER_H

#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <string.h>
#include <iostream>
#include <regex>

#include <string>
#include <sstream>
#include <vector>
#include <numeric>
#include <exception>

using namespace std;




class rationalNumber {
private:
    int numerator ;
    int denominator;
public:
    rationalNumber();
    ~rationalNumber();
    rationalNumber(int pwholeNum);//    1
    rationalNumber(int pnumerator,int pdenominator);//   1    "/"   1
    rationalNumber(string strNum);  //1/1
    int getNumerator();
    void setNumerator(int pnumerator);

    int getDenominator();
    void setDenominator(int pdenominator);

    friend ostream& operator<<(ostream& output, rationalNumber& rationalNumberOut);
//    rationalNumber& operator= (rationalNumber &rationalNum);

    rationalNumber operator+ (rationalNumber &rationalNum);
    rationalNumber operator- (rationalNumber &rationalNum);
    rationalNumber operator* (rationalNumber &rationalNum);
    rationalNumber operator/ (rationalNumber &rationalNum);

    bool operator== (rationalNumber &rationalNum);//bool return
    bool operator> (rationalNumber &rationalNum);//bool return
    bool operator< (rationalNumber &rationalNum);//bool return


};


#endif //A3RATIONAL_RATIONALNUMBER_H
