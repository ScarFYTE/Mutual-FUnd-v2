#pragma once
#include "Portfolio.h"

class AnalyticsManager {
public:
    std::string generateReport(const Portfolio &portfolio) const;
};
