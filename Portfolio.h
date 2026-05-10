#pragma once
#include <vector>
#include <map>
#include "MutualFund.h"
#include "User.h"
#include "Transaction.h"

class Portfolio {
private:
    std::map<std::string, int> holdings;
    std::vector<Transaction> history;

public:
    void buyUnits(User &user, MutualFund &fund, int units);
    void sellUnits(User &user, MutualFund &fund, int units);
    std::string getHoldingsDisplay() const;
    double totalInvestment(const std::vector<MutualFund>& funds) const;
    double currentValue(const std::vector<MutualFund>& funds) const;
    const std::vector<Transaction>& getHistory() const;
};
