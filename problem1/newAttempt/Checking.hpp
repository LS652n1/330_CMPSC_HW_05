#pragma once
#include "Account.hpp"

class Checking : public Account {
    public:
    void deposit (double amount) override;
    double withdraw (double amount) override;

    const std::string toString () override;

    void payOverDraft (double amount);      // Here because I just would like to add it.

    // For testing purposes
    unsigned int getAccNum () override;
    double getBalance ();
    double getRemainder (); 

    private:
    const double overdraftLimit = 100;
    double overdraftRemainder = 0;
};

void Checking::deposit (double amount) {
    balance += amount;
}

double Checking::withdraw (double amount) {
    // When you need to overdraft
        // When you can non longer overdraft (i.e. when you hit the limit), the there is still remaining amount asking for
        // When not asking for more then the overdraft limit remainder
    // When you don't need to overdraft
    double returnAmount = 0;
    if (balance < amount) {
        if (overdraftLimit - overdraftRemainder < amount - balance) {   
            returnAmount = (overdraftLimit - overdraftRemainder) + balance;     // Money recived from the remaing amount that can be overdrafted.
            overdraftRemainder = overdraftLimit;                        // Shows that now more can be overdrafted
        }
        else {
            returnAmount = amount - balance;
            overdraftRemainder += returnAmount; 
        }
        balance = 0;
    }
    else {
        balance -= amount;
        returnAmount = amount;
    }
    return returnAmount;
}   // What about when balance = 40, amount = 70, limit = 100, remainder = 80? => should give 20 back 
    // What about when balance = 40, amount = 70, limit = 100, remiander = 50? => shoudl give 30 back
    // Might add something that tells you how much difference you go vs what you asked for when amount - balacne > limit- remainder

const std::string Checking::toString() {
    return std::to_string(accNum) + "," + std::to_string(balance);
}

// Here because I would just like to add it
void Checking::payOverDraft(double amount) {
    if (overdraftRemainder != 0 && overdraftRemainder >= amount) {
        overdraftRemainder -= amount;
    }
    // Otherwise (when amount > remainder || remainder == 0)
}

// For test purposes
unsigned int Checking::getAccNum () {
    return accNum;
}
double Checking::getBalance () {
    return balance;
}
double Checking::getRemainder () {
    return overdraftRemainder;
}