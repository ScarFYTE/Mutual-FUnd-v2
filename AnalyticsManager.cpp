#include "AnalyticsManager.h"
#include <sstream>

std::string AnalyticsManager::generateReport(const Portfolio &portfolio) const {
    std::stringstream ss;
    ss << "Total Investment: Rs. (live)\n";
    ss << "Profit/Loss: (dynamic)\n";
    ss << "Return: (dynamic)\n";
    return ss.str();
}
