# Protrack Guide

**Author:** Team Alpha

## What This App Does
Protrack (Mutual Fund Investment Tracker) is a simple desktop application that lets you:
- Track a user’s balance and mutual fund holdings.
- Buy and sell units of mutual funds.
- View available funds and a live‑updating NAV display.
- See your portfolio summary and analytics.
- Save/load portfolio data between sessions.

---

## Quick Start (Windows)

### 1) Install SFML 3
Make sure SFML 3 is installed and that you have the **include**, **lib**, and **bin** folders available.

### 2) Build

#### Option A: CMake (recommended)
```bash
cmake -S . -B build
cmake --build build
```

#### Option B: Makefile
```bash
make
```
If SFML is in a custom location:
```bash
make SFML_INCLUDE=E:/SFML-3.1.0/include SFML_LIB=E:/SFML-3.1.0/lib
```

#### Option C: Single command (manual build)
```bash
g++ main.cpp User.cpp MutualFund.cpp Portfolio.cpp Transaction.cpp MarketEngine.cpp FileManager.cpp AnalyticsManager.cpp -o app -I "E:/SFML-3.1.0/include" -L "E:/SFML-3.1.0/lib" -lsfml-graphics -lsfml-window -lsfml-system
```

### 3) Run
1. Copy **SFML DLLs** from the SFML `bin` folder to the same folder as `app.exe`.
2. Place a font file named `arial.ttf` in the same folder as `app.exe`.
3. Run `app.exe`.

---

## Usage Instructions

- **Buy 10 Units**: Click the green button to buy 10 units of the first fund in the list.
- **Sell 10 Units**: Click the red button to sell 10 units of the first fund in the list.
- **Portfolio display** updates continuously, showing holdings and analytics.
- **Close the window** to save your data automatically.

---

## Project Structure (Beginner‑Friendly)

### `main.cpp`
**Purpose:** Entry point and UI loop.
- Creates the window and text elements.
- Displays user info, fund list, and portfolio summary.
- Handles button clicks for buy/sell.
- Calls `MarketEngine` to update NAVs.
- Uses `FileManager` to load/save data.

### `User.h / User.cpp`
**Purpose:** Represents the user.
- Stores name and balance.
- Functions for deposit, withdraw, and fetching balance/name.

### `MutualFund.h / MutualFund.cpp`
**Purpose:** Represents a single mutual fund.
- Stores fund name and current NAV.
- NAV changes when the market updates.

### `Portfolio.h / Portfolio.cpp`
**Purpose:** Tracks holdings and transactions.
- Stores how many units the user owns of each fund.
- Handles buying and selling units.
- Generates a holdings display string.
- Tracks transaction history.

### `Transaction.h / Transaction.cpp`
**Purpose:** Represents a buy/sell operation.
- Stores fund name, units, price, and type (BUY/SELL).

### `MarketEngine.h / MarketEngine.cpp`
**Purpose:** Simulates a market.
- Stores the list of funds.
- Updates NAV values periodically.
- Provides formatted fund list display.

### `FileManager.h / FileManager.cpp`
**Purpose:** Saves and loads data.
- Reads/writes user balance and portfolio to files.
- Ensures data persists across sessions.

### `AnalyticsManager.h / AnalyticsManager.cpp`
**Purpose:** Provides simple analytics.
- Generates a summary (e.g., total investment, performance).

---

## Common Errors (and Fixes)

### Missing SFML DLLs
**Error:** `sfml-graphics-3.dll was not found`
**Fix:** Copy DLLs from SFML `bin` folder next to `app.exe`.

### Missing Font
**Error:** `Font file missing (arial.ttf)`
**Fix:** Copy `C:\Windows\Fonts\arial.ttf` to your project folder and name it `arial.ttf`.

### Linker Errors (undefined reference)
**Cause:** You compiled only `main.cpp`.
**Fix:** Build all `.cpp` files together or use CMake/Makefile.

---

## Export This Guide to PDF
If you want a PDF, install **Pandoc**, then run:
```bash
pandoc docs/userguide.md -o docs/userguide.pdf
```

---

## Credits
Created by **Team Alpha**.
