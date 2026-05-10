#pragma once
#include "User.h"
#include "Portfolio.h"

class FileManager {
public:
    void saveData(const User &user, const Portfolio &portfolio);
    void loadData(User &user, Portfolio &portfolio);
};
