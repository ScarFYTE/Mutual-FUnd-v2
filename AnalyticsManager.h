#pragma once
#include "Portfolio.h"
#include <vector>

class AnalyticsManager {
public:
    std::string generateReport(const Portfolio &portfolio, const std::vector<MutualFund> &funds) const;
};
