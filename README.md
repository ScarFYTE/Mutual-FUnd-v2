# Mutual Fund Investment Tracker

A beginner-friendly C++ OOP project with a simple SFML GUI.

## Features
- View mutual funds
- Buy/Sell units
- Portfolio tracking
- Transaction history
- Save/Load data

## Build
```
g++ main.cpp User.cpp MutualFund.cpp Portfolio.cpp Transaction.cpp MarketEngine.cpp FileManager.cpp AnalyticsManager.cpp -o app -lsfml-graphics -lsfml-window -lsfml-system
```

Make sure `arial.ttf` is present in the project folder.
