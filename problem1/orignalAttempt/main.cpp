#include "Checking.hpp"
#include "Savings.hpp"

#include <iostream>
#include <memory>

void test1 () {
    //std::unique_ptr<Account> account = std::make_unique<Checking>();
    std::unique_ptr<Savings> savings = std::make_unique<Savings>();
    std::unique_ptr<Checking> checking = std::make_unique<Checking>();

    std::cout << "Savings -> accNum: " << savings->getAccountNumber() << std::endl;
    std::cout << "Checking -> accNum: " << checking->getAccountNumber() << std::endl;

}


int main () {
    test1();
    return 0;
}