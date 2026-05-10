#pragma once
#include <string>

class User {
private:
    std::string name;
    double balance;

public:
    User(std::string n = "Guest", double b = 0);
    ~User();
    std::string getName() const;
    double getBalance() const;
    void deposit(double amount);
    bool withdraw(double amount);
};
