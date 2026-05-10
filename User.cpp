#include "User.h"

User::User(std::string n, double b) : name(n), balance(b) {}
User::~User() {}

std::string User::getName() const { return name; }
double User::getBalance() const { return balance; }

void User::deposit(double amount) { balance += amount; }

bool User::withdraw(double amount) {
    if (amount > balance) return false;
    balance -= amount;
    return true;
}
