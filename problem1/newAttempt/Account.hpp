#pragma once
#include <string>
#include <ctime>

class Account {
    public:
    Account();

    virtual void deposit (double amount) = 0;
    virtual double withdraw (double amount) = 0;

    virtual const std::string toString () = 0;

    ~Account();

    // For testing purposes
    virtual unsigned int getAccNum () = 0;
    std::string getDateCreated () const;

    protected:
    unsigned int accNum;
    double balance;
    const double interrest = 0.232;
    std::string dateCreated;
};

Account::Account() {
    srand(0);
    accNum = rand () % 4294967295 + 1000000000; // Between 1 billion and unsigned int limit
    balance = 0;

    std::time_t currTime = std::time(0);
    std::tm * now = std::localtime(&currTime);
    dateCreated = std::to_string(now->tm_mon + 1) + "/" + std::to_string(now->tm_mday) + "/" + std::to_string(now->tm_year + 1900);
}

Account::~Account() {}

std::string Account::getDateCreated() const {
    return dateCreated; 
}