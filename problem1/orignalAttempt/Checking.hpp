#pragma once
#include "account.hpp"

class Checking : public Account {
    public:
    double withdraw (double amount) override;
    void deposit (double amount) override;
    const std::string toString (unsigned int accNum, double balance) override;


    // For test Purposes
    unsigned int getAccountNumber () override;

    private:
    const double overdrawlimit = 100;
    double amountOverdrawed = 0;
};

double Checking::withdraw (double amount) {   // When the amount wanting to widthdraw exceeds the overdraw limit then I should probally give a return value for widthdraw.
    double withdrawnAmount;
    if (balance < amount) {
        //double overdrawnMoney;
        if (overdrawlimit - amountOverdrawed < amount - balance) {  // When asking for more then the current max amount possible to borrow
            //overdrawnMoney = overdrawlimit - amountOverdrawed;
            withdrawnAmount = overdrawlimit - amountOverdrawed;
            amountOverdrawed = overdrawlimit;
        }
        else {
            withdrawnAmount = amount - balance;
            amountOverdrawed += withdrawnAmount;
        }
        balance = 0;
    }
    else {
        balance -= amount;
        withdrawnAmount = amount;
    }
    return withdrawnAmount;
}


void Checking::deposit (double amount) {
    balance += amount;
}

const std::string Checking::toString (unsigned int accNum, double balance) {
    return std::to_string(accNum) + "," + std::to_string(balance);
}

// For testing Purposes
unsigned int Checking::getAccountNumber () {
    return accNum;
} 