#include "MutualFund.h"
#include <cstdlib>

MutualFund::MutualFund(std::string name, double nav, std::string risk, double ret)
    : fundName(name), nav(nav), riskLevel(risk), annualReturn(ret) {}

MutualFund::~MutualFund() {}

void MutualFund::updateNAV() {
    double change = ((rand() % 5) - 2) / 100.0;
    nav += nav * change;
}

std::string MutualFund::getName() const { return fundName; }
double MutualFund::getNAV() const { return nav; }
std::string MutualFund::getRisk() const { return riskLevel; }
double MutualFund::getReturn() const { return annualReturn; }
