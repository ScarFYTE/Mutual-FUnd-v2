#include "MarketEngine.h"
#include <sstream>

MarketEngine::MarketEngine() {
    funds.emplace_back("Alpha Growth", 100, "Medium", 12.5);
    funds.emplace_back("Secure Bond", 80, "Low", 7.2);
    funds.emplace_back("Equity Plus", 150, "High", 15.1);
}

void MarketEngine::updateNAVs() {
    for (auto &f : funds) f.updateNAV();
}

const std::vector<MutualFund>& MarketEngine::getFunds() const { return funds; }

std::string MarketEngine::getFundsDisplay() const {
    std::stringstream ss;
    for (auto &f : funds) {
        ss << f.getName() << " | NAV: " << (int)f.getNAV()
           << " | Risk: " << f.getRisk() << "\n";
    }
    return ss.str();
}
