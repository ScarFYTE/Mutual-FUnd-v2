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
    void buyUnits(User &user, const MutualFund &fund, int units);
    void sellUnits(User &user, const MutualFund &fund, int units);
    std::string getHoldingsDisplay() const;
    double totalInvestment(const std::vector<MutualFund>& funds) const;
    double currentValue(const std::vector<MutualFund>& funds) const;
    const std::vector<Transaction>& getHistory() const;
    int getUnitsForFund(const std::string &fundName) const;
    double getNetInvestedForFund(const std::string &fundName) const;
    const std::map<std::string, int>& getHoldings() const;
};
