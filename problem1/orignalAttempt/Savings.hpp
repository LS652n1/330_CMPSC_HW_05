#pragma once
#include "account.hpp"

class Savings : public Account {
    public:
    double withdraw (double amount) override;     // I might not want to override this one
    void deposit (double amount) override;

    const std::string toString (unsigned int numAcc, double balance) override;

    // For test Purposes
    unsigned int getAccountNumber () override;
};


                                        // might need override here
double Savings::withdraw (double amount) {
    double returnAmount;
    if (balance < amount) {
        returnAmount = balance;
        balance = 0;
    }
    else {
        balance -= amount;
        returnAmount = amount;
    }
    
    return returnAmount;
}

void Savings::deposit (double amount) {
    balance += amount;
}


const std::string Savings::toString (unsigned int numAcc, double balance) {
    return std::to_string(numAcc) + "," + std::to_string(balance);
}

unsigned int Savings::getAccountNumber () {
    return accNum;
}