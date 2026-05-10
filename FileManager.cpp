#include "FileManager.h"
#include <fstream>

void FileManager::saveData(const User &user, const Portfolio &portfolio) {
    std::ofstream file("save.txt");
    file << user.getName() << "\n" << user.getBalance() << "\n";
    file.close();
}

void FileManager::loadData(User &user, Portfolio &portfolio) {
    std::ifstream file("save.txt");
    if (file) {
        std::string name;
        double balance;
        getline(file, name);
        file >> balance;
        user = User(name, balance);
    }
    file.close();
}
