#pragma once
#include <vector>
#include "MutualFund.h"

class MarketEngine {
private:
    std::vector<MutualFund> funds;

public:
    MarketEngine();
    void updateNAVs();
    const std::vector<MutualFund>& getFunds() const;
    std::string getFundsDisplay() const;
};
