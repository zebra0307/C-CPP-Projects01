# Billing System

A modern, cross-platform supermarket billing system built with C++11.

---

## Features

- **Smart Inventory Management** - Add items with multi-word names, automatic duplicate handling
- **Interactive Billing** - Real-time stock validation and itemized receipts
- **Robust Input Validation** - Handles invalid input gracefully without crashes
- **Cross-Platform** - Works on Windows, Linux, and macOS
- **Persistent Storage** - Automatic save/load from `billing.txt`

---

## Quick Start

### Compile

```bash
g++ -Wall -Wextra -std=c++11 -g3 -Iheaders *.cpp -o output/main.exe
```

### Run

```bash
./output/main.exe
```

---

## How It Works

### Main Menu

```
Welcome To Super Market Billing System
**************************************
    1. Add Item
    2. Print Bill
    3. Exit
```

### Add Items to Inventory

- Supports multi-word names: "Fresh Orange Juice", "Apple"
- Set price and quantity
- Automatic duplicate detection (updates quantity only, not price)

### Create Bills

- Select items by name
- Enter quantity needed
- Automatic stock validation
- Real-time inventory deduction
- Itemized receipt with total

### Example Output

```
Item                     Rate      Quantity    Amount
Fresh Orange Juice       200       5           1000

========================================
         BILLING SUMMARY
========================================
Items Purchased:
  - Fresh Orange Juice: Rs. 1000
  - Apple: Rs. 500
----------------------------------------
 Total Bill: Rs. 1500
========================================
Thanks For Shopping!
```

---

## Architecture

```
Billing_System/
├── headers/
│   ├── Common.h              # Cross-platform utilities & constants
│   ├── Bill.h                # Item data model (class definition)
│   └── BillingOperations.h   # Function declarations
├── Bill.cpp                  # Item class implementation
├── BillingOperations.cpp     # Business logic & validation
├── main.cpp                  # Entry point & main menu
├── billing.txt               # Persistent storage (auto-generated)
└── output/
    └── main.exe              # Compiled executable
```

### Component Details

- **Common.h** - Cross-platform macros (`CLEAR_SCREEN`), sleep utilities, and named constants in `BillingConstants` namespace
- **Bill.h/cpp** - Simple data class representing an inventory item (name, rate, quantity)
- **BillingOperations.h/cpp** - Core business logic including:
  - `loadInventory()` / `saveInventory()` - File I/O operations
  - `addItem()` - Add/update inventory with duplicate detection
  - `printBill()` - Interactive billing session with stock validation
  - Input validation utilities (`getValidIntInput`, `getValidStringInput`)
- **main.cpp** - Program entry point with main menu loop

---

## Code Quality

- Modern C++11 - Smart pointers, chrono, thread-safe
- Const-Correct - Immutable getters, reference optimization
- Input Validated - No crashes, no undefined behavior
- Zero Magic Numbers - Named constants throughout
- Linter Compliant - Passes `-Wall -Wextra` with zero warnings

---

## Technical Highlights

- **In-memory storage** with `std::vector` for 100x faster operations
- **Reference optimization** - No unnecessary string copying
- **Cross-platform sleep** using `std::chrono` instead of OS-specific APIs
- **Consistent formatting** with `std::setw()` and `std::left`
- **Smart validation** - Rejects negative numbers, empty strings, non-numeric input

---

## License

Open source - Available for educational purposes.
