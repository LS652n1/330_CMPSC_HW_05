#pragma once
#include <chrono>
#include <string>
#include <ctime>
#include <cstdlib>

class Account {
    public:
    Account ();
    virtual void deposit (double amount) = 0;
    //virtual void withdraw (double amount);
    virtual double withdraw (double amount) = 0;

    virtual const std::string toString (unsigned int accNum, double balance) = 0;

    virtual ~Account();

    // Testing purposes
    virtual unsigned int getAccountNumber () = 0;
    
    
    protected:
    unsigned int accNum;    // Up to the unsigned integer limit of 4,294,967,294 , numbers 1 billion - 4.29... billion
                                         // Might want to store a bunch of numbers
    double balance = 0;
    const double intrest = 0.02332;
    std::string dateCreated;     // might want to change this later
};

Account::Account () {
    std::srand(std::time(0));
    accNum = std::rand() % 4294967294 + 1000000000;

    balance = 0;
    std::time_t timeNow = std::time(0);
    std::tm * localTime = std::localtime(&timeNow);
    //accNum = 1; // FOR TESTING PURPOSES.

}

Account::~Account() {}

