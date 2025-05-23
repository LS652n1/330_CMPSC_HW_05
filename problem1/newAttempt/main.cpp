#include "Checking.hpp"
#include "Savings.hpp"

#include <iostream>
#include <assert.h>

int main () {
    Savings * savings = new Savings();
    Checking * checking = new Checking();

    std::cout << "Savings-> accNum: " << savings->getAccNum() << std::endl;
    std::cout << "Checking-> accNum: " << checking->getAccNum() << std::endl;
    
    assert (savings->getAccNum() == checking->getAccNum());

    assert (savings->getBalance() == 0);
    assert (savings->toString() == std::to_string(savings->getAccNum()) + "," + std::to_string((double) 0));

    savings->deposit(50);
    assert (savings->getBalance() == 50);

    
    savings->withdraw(50);
    assert (savings->getBalance() == 0);
    
    savings->deposit(100);
    assert (savings->withdraw(150) == 0);

    savings->withdraw(0);
    assert (savings->getBalance() == 100);


    assert (savings->toString() == std::to_string(savings->getAccNum()) + "," + std::to_string((double) 100));

    std::cout << "All savings test have passed. Now going to the checking test" << std::endl;
    
    assert (checking->toString() == std::to_string(checking->getAccNum()) + "," + std::to_string((double) 0));

    checking->deposit(100.00);
    assert(checking->getBalance() == 100.00);

    checking-> withdraw(50);
    assert(checking->getBalance() == 50.00);

    checking->withdraw(100);
    assert(checking->getRemainder() == (double) 50);

    assert(checking->withdraw(100) == 50);
    assert(checking->getRemainder() == 100);    // 100 because, at the time of writting this, it is the overdraftlimit.

    checking->payOverDraft(100);

    assert(checking->withdraw(130) == 100);
    assert(checking->getBalance() == 0 && checking->getRemainder() == 100);

    checking->payOverDraft(100);
    checking->deposit(35);
    assert(checking->withdraw(20) == 20);
    assert(checking->getBalance() == 15);
    assert(checking->withdraw(160) == 115 && checking->getBalance() == 0 && checking->getRemainder() == 100);

    std::cout << "Saving says today's date is: " << savings->getDateCreated() << std::endl;
    std::cout << "Checking says today's date is: " << checking->getDateCreated() << std::endl;

    std::cout << "All checking test have been passed" << std::endl;
    
    std::cout << "All test have been passed." << std::endl;

    return 0;
}

