#pragma once
#include <string>

class Transaction {
private:
    std::string fundName;
    int units;
    double price;
    std::string type;

public:
    Transaction(std::string fund, int units, double price, std::string type);
    std::string toString() const;
    const std::string& getFundName() const;
    int getUnits() const;
    double getPrice() const;
    const std::string& getType() const;
};
