#pragma once
#include <string>

class MutualFund {
protected:
    std::string fundName;
    double nav;
    std::string riskLevel;
    double annualReturn;

public:
    MutualFund(std::string name, double nav, std::string risk, double ret);
    virtual ~MutualFund();
    virtual void updateNAV();
    std::string getName() const;
    double getNAV() const;
    std::string getRisk() const;
    double getReturn() const;
};
