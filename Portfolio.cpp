#include "Portfolio.h"
#include <sstream>

void Portfolio::buyUnits(User &user, MutualFund &fund, int units) {
    double cost = fund.getNAV() * units;
    if (user.withdraw(cost)) {
        holdings[fund.getName()] += units;
        history.emplace_back(fund.getName(), units, fund.getNAV(), "BUY");
    }
}

void Portfolio::sellUnits(User &user, MutualFund &fund, int units) {
    if (holdings[fund.getName()] >= units) {
        holdings[fund.getName()] -= units;
        double gain = fund.getNAV() * units;
        user.deposit(gain);
        history.emplace_back(fund.getName(), units, fund.getNAV(), "SELL");
    }
}

std::string Portfolio::getHoldingsDisplay() const {
    std::stringstream ss;
    for (auto &h : holdings)
        ss << h.first << ": " << h.second << " units\n";
    return ss.str();
}

double Portfolio::totalInvestment(const std::vector<MutualFund>& funds) const {
    double total = 0;
    for (auto &h : holdings) {
        for (auto &f : funds) {
            if (f.getName() == h.first)
                total += f.getNAV() * h.second;
        }
    }
    return total;
}

double Portfolio::currentValue(const std::vector<MutualFund>& funds) const {
    return totalInvestment(funds);
}

const std::vector<Transaction>& Portfolio::getHistory() const {
    return history;
}
