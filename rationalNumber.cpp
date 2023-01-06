
#include "rationalNumber.h"
rationalNumber::~rationalNumber() {

    string toStr = to_string(this->numerator);
    toStr +="/";
    toStr += to_string(this->denominator);
    cout<<"rational number "<<to_string(this->numerator)<<"/"<< to_string(this->denominator)<<" was Deleted"<<endl;
}
rationalNumber::rationalNumber() {
    cout<<"default constructor fired"<<endl;
}

rationalNumber::rationalNumber(int pWholeNum) {
    cout<<"One int Arg constructor fired"<<endl;
    if(pWholeNum !=0)
    {
        this->numerator = pWholeNum;
        this->denominator = 1;
    }
    else{  cout << "Invalid rational number format\n";}
}
rationalNumber::rationalNumber(int pNumerator, int pDenominator) {
    cout<<"Two int Arg constructor fired"<<endl;
    if(pNumerator<0 && pDenominator<0){pNumerator =pNumerator * -1; pDenominator = pDenominator *-1;}
    if(pNumerator>0 && pDenominator<0){pNumerator =pNumerator * -1; pDenominator = pDenominator *-1;}
    this->numerator = pNumerator;
    this->denominator = pDenominator;
}
rationalNumber::rationalNumber(string strNum) {
    cout<<"One string Arg constructor fired"<<endl;
    bool isFraction=false;
    bool isWhole=false;
    bool hitDelim=false;
    string num1,num2;
    char delim = '/';
    regex r1 {"^[-|0-9][0-9]*(\\/)[-|0-9][0-9]*$"};
    regex r2 {"^[-|0-9][0-9]*$"};
    if (regex_match (strNum, r1 ))
    {    isFraction=true;}
    else if (regex_match (strNum, r2 ))
    {   isWhole=true;}
    if(isFraction){
        for(int i=0; i<strNum.length();i++){
            if(  strNum[i]==delim){
                hitDelim=true;
            }
            if(!hitDelim){
                num1 += strNum[i];
            }
            else if(hitDelim && strNum[i] !=delim){
                num2 += strNum[i];
            }
        }
        int tempNumerator= stoi(num1);
        int tempDenominator = stoi(num2);
        if(tempNumerator<0 && tempDenominator<0){tempNumerator =tempNumerator * -1; tempDenominator = tempDenominator *-1;}
        if(tempNumerator>0 && tempDenominator<0){tempNumerator =tempNumerator * -1; tempDenominator = tempDenominator *-1;}
        this->numerator = tempNumerator;
        this->denominator = tempDenominator;
    }
    else if(isWhole){
        num1 = strNum;
        num2="1";
        this->numerator = stoi(num1);
        this->denominator = stoi(num2);
    }
    else{  cout << "Invalid rational number format"<<endl;}
}

int rationalNumber::getNumerator() {
    return this->numerator;
}
void rationalNumber::setNumerator(int pNumerator) {
    this->numerator= pNumerator;
}
int rationalNumber::getDenominator() {
    return this->denominator;
}
void rationalNumber::setDenominator(int pDenominator) {
    this->denominator= pDenominator;
}

//rationalNumber &rationalNumber::operator=(rationalNumber &rationalNum) {
//    cout<<"'=' operator fired"<<endl;
//    this->setNumerator(rationalNum.getNumerator());
//    this->setDenominator(rationalNum.getDenominator());
//    return *this;
//
//}

ostream &operator<<(ostream &output, rationalNumber &rationalNumberOut) {
//    cout<<"'<<' operator fired"<<endl;
    output <<
           to_string(rationalNumberOut.getNumerator())<<
           "/" <<
           to_string(rationalNumberOut.getDenominator());
    return output;//return an ostream
}



rationalNumber rationalNumber::operator+(rationalNumber &rationalNum) {
    cout<<"'+' operator fired"<<endl;
    int num1, num2, den1, den2;
    num1 = this->getNumerator();
    num2= rationalNum.getNumerator();
    den1=this->getDenominator();
    den2=rationalNum.getDenominator();
    int den3 = den1 * den2;
            num1= num1 * den2;
            num2 = num2 * den1;
   int num3 =(num1 + num2);
    int gcd = __gcd( num3 , den3 );
    return rationalNumber((num3/gcd),(den3/gcd));
}

rationalNumber rationalNumber::operator-(rationalNumber &rationalNum) {
    cout<<"'-' operator fired"<<endl;
    int num1, num2, den1, den2;
    num1 = this->getNumerator();
    num2= rationalNum.getNumerator();
    den1=this->getDenominator();
    den2=rationalNum.getDenominator();
    int den3 = den1 * den2;
    num1= num1 * den2;
    num2 = num2 * den1;
    int num3 =(num1 - num2);
    int gcd = __gcd( num3 , den3 );
    return rationalNumber((num3/gcd),(den3/gcd));

}

rationalNumber rationalNumber::operator*(rationalNumber &rationalNum) {
    cout<<"'*' operator fired"<<endl;
    int newNumerator, newDenominator;
    int num1, num2, den1, den2;
    num1 = this->getNumerator();
    num2= rationalNum.getNumerator();
    den1=this->getDenominator();
    den2=rationalNum.getDenominator();
    newNumerator=num1*num2;
    newDenominator=den1*den2;
    int gcd = __gcd( newNumerator , newDenominator );
    return rationalNumber((newNumerator/gcd),(newDenominator/gcd));
}

rationalNumber rationalNumber::operator/(rationalNumber &rationalNum) {
    cout<<"'/' operator fired"<<endl;
    int newNumerator, newDenominator;
    int num1, num2, den1, den2;

    num1 = this->getNumerator();//FLIPPED denominator an numerator
    den1=this->getDenominator();//FLIPPED denominator an numerator
    den2= rationalNum.getNumerator();
    num2=rationalNum.getDenominator();
    if(num1==0 && num2==0){
        newNumerator=0;
    }
    else{ newNumerator=num1*num2;}


    newDenominator=den1*den2;

    int gcd = __gcd( newNumerator , newDenominator );
    return rationalNumber((newNumerator/gcd),(newDenominator/gcd));
}

bool rationalNumber::operator>(rationalNumber &rationalNum) {
    cout<<"'>' operator fired"<<endl;
    bool greaterThan=false;
    int num1, num2, den1, den2;
    num1 = this->getNumerator();
    num2= rationalNum.getNumerator();
    den1=this->getDenominator();
    den2=rationalNum.getDenominator();
    int den3 = den1 * den2;
    num1= num1 * den2;
    num2 = num2 * den1;
    if(num1>num2){greaterThan=true;}
    return greaterThan;
}

bool rationalNumber::operator<(rationalNumber &rationalNum) {
    cout<<"'<' operator fired"<<endl;
    bool greaterThan=false;
    int num1, num2, den1, den2;
    num1 = this->getNumerator();
    num2= rationalNum.getNumerator();
    den1=this->getDenominator();
    den2=rationalNum.getDenominator();
    int den3 = den1 * den2;
    num1= num1 * den2;
    num2 = num2 * den1;
    if(num1<num2){greaterThan=true;}
    return greaterThan;
}

bool rationalNumber::operator==(rationalNumber &rationalNum) {
    cout<<"'==' operator fired"<<endl;
    bool greaterThan=false;
    double num1, num2, den1, den2;
    num1 = this->getNumerator();
    num2= rationalNum.getNumerator();
    den1=this->getDenominator();
    den2=rationalNum.getDenominator();
    if(num1/den1==num2/den2){greaterThan=true;}
    return greaterThan;
}





