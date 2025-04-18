#pragma once
#include "Account.hpp"

class Savings : public Account {
    public:
    void deposit (double amount) override;
    double withdraw (double amount) override;

    const std::string toString () override;
    
    // For testing purposes
    unsigned int getAccNum () override;
    double getBalance ();

    private:
};

void Savings::deposit (double amount) {
    balance += amount;
}
double Savings::withdraw (double amount) {
    if (balance >= amount) {
        balance -= amount;
        return amount;
    }
    return (double) 0;
}

const std::string Savings::toString () {
    return std::to_string(accNum) + "," + std::to_string(balance);
}

// For testing purposes
unsigned int Savings::getAccNum () {
    return accNum;
}

double Savings::getBalance () {
    return balance;
}