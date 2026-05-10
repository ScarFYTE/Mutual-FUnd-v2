#include "AnalyticsManager.h"
#include <iomanip>
#include <sstream>

std::string AnalyticsManager::generateReport(const Portfolio &portfolio,
                                             const std::vector<MutualFund> &funds) const {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2);

    double totalInvested = 0.0;
    double totalCurrent = 0.0;

    for (const auto &fund : funds) {
        int units = portfolio.getUnitsForFund(fund.getName());
        if (units <= 0) {
            continue;
        }

        double invested = portfolio.getNetInvestedForFund(fund.getName());
        double current = units * fund.getNAV();
        double profit = current - invested;
        double returnPct = invested > 0.0 ? (profit / invested) * 100.0 : 0.0;

        totalInvested += invested;
        totalCurrent += current;

        ss << fund.getName() << " -> Units: " << units
           << " | Invested: Rs. " << invested
           << " | Value: Rs. " << current
           << " | P/L: Rs. " << profit
           << " | Return: " << returnPct << "%\n";
    }

    double totalProfit = totalCurrent - totalInvested;
    double totalReturn = totalInvested > 0.0 ? (totalProfit / totalInvested) * 100.0 : 0.0;

    ss << "\nTotal Invested: Rs. " << totalInvested << "\n";
    ss << "Total Value: Rs. " << totalCurrent << "\n";
    ss << "Total Profit/Loss: Rs. " << totalProfit << "\n";
    ss << "Total Return: " << totalReturn << "%";
    return ss.str();
}
