cmake_minimum_required(VERSION 3.20)
project(MutualFundInvestmentTracker LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

add_executable(app
    main.cpp
    User.cpp
    MutualFund.cpp
    Portfolio.cpp
    Transaction.cpp
    MarketEngine.cpp
    FileManager.cpp
    AnalyticsManager.cpp
)

target_link_libraries(app PRIVATE SFML::Graphics SFML::Window SFML::System)
