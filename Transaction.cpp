#include "Transaction.h"

Transaction::Transaction(std::string fund, int u, double p, std::string t)
    : fundName(fund), units(u), price(p), type(t) {}

std::string Transaction::toString() const {
    return type + " " + std::to_string(units) + " units of " + fundName +
           " at Rs." + std::to_string((int)price);
}

const std::string& Transaction::getFundName() const {
    return fundName;
}

int Transaction::getUnits() const {
    return units;
}

double Transaction::getPrice() const {
    return price;
}

const std::string& Transaction::getType() const {
    return type;
}
