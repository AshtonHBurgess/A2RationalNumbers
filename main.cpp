//w0465511
//Ashton Burgess
#include "rationalNumber.h"
void performRationalNumberMathTest(rationalNumber &r1, rationalNumber &r2);
bool fractionStringValidation(string strNum);
void askForTwoRationalNumbers();

int main() {
    string quit;
    do{
        askForTwoRationalNumbers();
        cout << "Input 'quit' to quit program:" << endl;
        cin >> quit;
    }while(quit !="quit");
    return 0;
}

void performRationalNumberMathTest(rationalNumber &r1, rationalNumber &r2) {
    cout<<"\nADD a= (b + c)\n";
    rationalNumber r3=r1+r2;
    cout<<r3<<endl;
    cout<<"\nSUB a= (b - c)\n";
    r3= r1-r2;
    cout<<r3<<endl;
    cout<<"\nMULTI a= (b * c)\n";
    r3=r1*r2;
    cout<<r3<<endl;
    cout<<"\nDIV a = (b / c)\n";
    r3=r1/r2;
    cout<<r3<<endl;
    cout<<"\nIs "<<r1<<" Larger Than "<<r2<<" :"<<endl;;
    if(r1>r2){cout<<"Yes,"<<r1<<" is Larger"<<endl;}
    if(r1<r2){cout<<"No,"<<r1<<" is Smaller"<<endl;}
    if(r1==r2){cout<<"No,"<<r1<< " and "<<r2<<" are Equal"<<endl;}
}


bool fractionStringValidation(string strNum){
    regex r1 {"^[-|0-9][0-9]*(\\/)[-|0-9][0-9]*$"};
    bool hitDelim=false,isValidFraction=false,isFraction=(regex_match (strNum, r1 ));;
    string num1,num2;
    char delim='/';
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
    }
    if(isFraction){
        string zero;
        for(int i=0; i<num2.length();i++){zero+="0";}
        string negZero="-";
        for(int i=0; i<(num2.length()-1);i++){negZero+="0";}
        if(num2 != zero && num2 !=negZero) {
            isValidFraction = true;
        }
    }
    return isValidFraction;
}

bool WholeNumberStringValidation(string strNum){
    bool validNotZero=false;
    regex r2 {"^[-|0-9][0-9]*$"};
    if((regex_match (strNum, r2 ))){
        return true;
    }
    return false;
}


void askForTwoRationalNumbers(){
    string str1, str2;
    bool validWholeNum=false, validFraction=false,validRationalNumber=false;
    while(!validRationalNumber) {
        cout << "Input entire first fraction (or whole number) as a string:" << endl;
        cin >> str1;
        if(WholeNumberStringValidation(str1) ){    validWholeNum = true;}
        if(fractionStringValidation(str1) ){validFraction = true;}
        if(validFraction || validWholeNum){validRationalNumber=true;}
    }
    validWholeNum=false, validFraction=false,validRationalNumber=false;
    while(!validRationalNumber) {
        cout << "Inputs entire second fraction (or whole number) as a string:" << endl;
        cin >> str2;
        if(WholeNumberStringValidation(str2) ){    validWholeNum = true;}
        if(fractionStringValidation(str2) ){    validFraction = true;}
        if(validFraction || validWholeNum){validRationalNumber=true;}
    }
      rationalNumber r1(str1);
      rationalNumber r2(str2);
    try{
        if(r1.getNumerator()==0&&r2.getNumerator()==0){throw exception();}
        performRationalNumberMathTest(r1,r2);}
    catch(exception e){cout<<"\nThis program will not allow you to attempt to divide 0 by 0.\n"<<endl; e.what();}

}


