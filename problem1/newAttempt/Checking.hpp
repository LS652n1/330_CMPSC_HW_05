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
    
    double returnAmount = 0;
    if (balance < amount) {     // When needing to overdraft
        if (overdraftLimit - overdraftRemainder < amount - balance) {       // When you can not longer overdraft
            returnAmount = (overdraftLimit - overdraftRemainder) + balance;     // Money recived from the remaing amount that can be overdrafted.
            overdraftRemainder = overdraftLimit;                        // Shows that now more can be overdrafted
        }
        else {                  // When you are still able to overdraft 
            returnAmount = amount - balance;
            overdraftRemainder += returnAmount; 
        }
        balance = 0;
    }
    else {                      // When you do not need to overdraft
        balance -= amount;
        returnAmount = amount;
    }
    return returnAmount;
}    

const std::string Checking::toString() {
    return std::to_string(accNum) + "," + std::to_string(balance);
}

// Here because I would just like to add it
void Checking::payOverDraft(double amount) {
    if (overdraftRemainder != 0 && overdraftRemainder >= amount) {
        overdraftRemainder -= amount;
    }
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