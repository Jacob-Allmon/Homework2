/**********************************************************************************************************
** Author: Jacob Allmon
** Program: HW2 Q2
 * Problems: the overloaded "<<" operater in the check structure. Also do copy constructor and destructor.
 *********************************************************************************************************/


#include <iostream>
#include <string>
using namespace std;
//this is the check struct//
struct Check{
    int CheckNum;
    string CheckMemo;
    float CheckAmount;
    bool operator >(float amount);
    void operator <<(Check check);
};

class CheckBook{
public:
    CheckBook(){balance=0;numOfChecks=0;checkBookSize=4;}
    CheckBook(float x){balance=x;numOfChecks=0;checkBookSize=4;}
    Check* checkPtr;
    float getBalance(){return balance;}
    void setBalance(float x){balance=x;}
    double getLastDeposit(){return lastDeposit;}
    void setLastDeposit(double x){lastDeposit=x;}
    int getNumOfChecks(){return numOfChecks;}
    void setNumOfChecks(int x){numOfChecks=x;}
    int getCBSize(){return checkBookSize;}
    void setCBSize(int x){checkBookSize=x;}
    void operator =(CheckBook x);
    void deposit(float x){balance=balance+x;}
private:
    float balance;
    double lastDeposit;
    int numOfChecks;
    int checkBookSize;

};


int main() {
    CheckBook CheckBookTest(250);
    CheckBook CheckBookTest2(300);
    cout<<CheckBookTest.getBalance()<<endl;
    CheckBookTest=CheckBookTest2;
    cout<<CheckBookTest.getBalance()<<endl;
    CheckBookTest.deposit(400);
    cout<<CheckBookTest.getBalance()<<endl;

    return 0;
}
//These are the overloaded operators//
bool Check::operator>(float amount) {
    if (CheckAmount>amount){
        return true;
    }
    else if (CheckAmount<amount){
        return false;
    }
}
void Check::operator<<(Check check) {
    cout<<check.CheckNum;
}
void CheckBook::operator =(CheckBook x){
    balance=x.balance;
    lastDeposit=x.lastDeposit;
    numOfChecks=x.numOfChecks;
    checkBookSize=x.checkBookSize;
}