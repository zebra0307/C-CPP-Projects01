# 🛒 Super Market Billing System

A comprehensive **C++ console-based billing system** designed for supermarkets to manage inventory and generate bills efficiently. This project demonstrates object-oriented programming concepts, file handling, and modular code organization.

---

## 📋 Table of Contents

- [Features](#-features)
- [Project Structure](#-project-structure)
- [Technologies Used](#-technologies-used)
- [Installation & Setup](#-installation--setup)
- [How to Use](#-how-to-use)
- [Code Overview](#-code-overview)
- [Future Enhancements](#-future-enhancements)
- [Contributing](#-contributing)

---

## ✨ Features

- **Add Items to Inventory**: Store item name, rate, and quantity in a text file
- **Generate Bills**: Search for items and calculate total bill amount
- **Inventory Management**: Automatically updates inventory after each purchase
- **Persistent Storage**: All data stored in `billing.txt` for future sessions
- **User-Friendly Interface**: Simple console-based menu system
- **Error Handling**: Validates item availability and quantity before billing

---

## 📁 Project Structure

```
Billing_System/
│
├── headers/                    # Header files directory
│   ├── Common.h               # Common includes and namespace
│   ├── Bill.h                 # Bill class declaration
│   └── BillingOperations.h    # Function declarations for operations
│
├── main.cpp                   # Main program entry point
├── Bill.cpp                   # Bill class implementation
├── BillingOperations.cpp      # Billing operations implementation
├── billing.txt                # Data storage file (auto-generated)
├── output/                    # Compiled executable directory
│   └── main.exe
├── .gitignore                 # Git ignore file
└── README.md                  # Project documentation
```

---

## 🛠️ Technologies Used

- **Language**: C++
- **Platform**: Windows (uses Windows-specific APIs like `Sleep()` and `system("cls")`)
- **Compiler**: GCC/MinGW or MSVC (Visual Studio)
- **File I/O**: Standard C++ streams (`fstream`, `ifstream`, `ofstream`)

---

## 📥 Installation & Setup

### Prerequisites

- **C++ Compiler**: MinGW-w64 (GCC) or Visual Studio
- **Git**: To clone the repository
- **Windows OS**: Required for Windows-specific functions

### Compilation

#### Using GCC/MinGW:

```bash
# Navigate to the project directory
cd Billing_System

# Compile all source files
g++ -o output/main.exe main.cpp Bill.cpp BillingOperations.cpp

# Run the executable
./output/main.exe
```

#### Using Visual Studio:

1. Open the project folder in Visual Studio
2. Add all `.cpp` and `.h` files to the project
3. Build and Run (F5)

---

## 🚀 How to Use

### 1️⃣ **Add Items to Inventory**

- Select option `1` from the main menu
- Choose `1` to add an item
- Enter:
  - **Item Name** (e.g., `Laptop`)
  - **Rate** (price per unit, e.g., `50000`)
  - **Quantity** (available stock, e.g., `10`)
- Item is saved to `billing.txt`
- Choose `2` to return to the main menu

### 2️⃣ **Generate Bill**

- Select option `2` from the main menu
- Choose `1` to add items to the bill
- Enter:
  - **Item Name** (must exist in inventory)
  - **Quantity** to purchase
- System calculates and displays:
  - Item details
  - Total amount for that item
- Inventory is automatically updated
- Choose `2` when done to see the **Total Bill**

### 3️⃣ **Exit**

- Select option `3` to exit the application

---

## 💻 Code Overview

### **Class Structure**

#### `Bill` Class (`Bill.h` & `Bill.cpp`)

Represents a single item in the billing system:

```cpp
class Bill {
private:
    string Item;      // Item name
    int Rate;         // Price per unit
    int Quantity;     // Available quantity

public:
    // Getters and setters
    void setItem(string item);
    void setRate(int rate);
    void setQuant(int quant);

    string getItem();
    int getRate();
    int getQuant();
};
```

### **Core Functions**

#### `addItem()` - Add items to inventory

- Takes user input for item details
- Appends data to `billing.txt`
- Format: `Item : Rate : Quantity`

#### `printBill()` - Generate customer bill

- Searches for items in inventory
- Validates quantity availability
- Calculates total amount
- Updates inventory after purchase
- Displays final bill

### **Data Storage Format**

`billing.txt`:

```
    bag : 500 : 31
    jeans : 400 : 41
    shoes : 1000 : 60
    books : 100 : 60
```

---

## 🔮 Future Enhancements

- [ ] Add **receipt printing** functionality
- [ ] Implement **login system** (admin/cashier)
- [ ] Add **search and delete** item features
- [ ] Create **graphical user interface** (GUI) using Qt/wxWidgets
- [ ] Database integration (MySQL/SQLite)
- [ ] Generate **PDF bills**
- [ ] Add **discount and tax** calculations
- [ ] Support for **multiple payment methods**
- [ ] Cross-platform compatibility (Linux/macOS)

---

## 🤝 Contributing

This project is part of the **C-CPP-Projects** open-source repository. Contributions, issues, and feature requests are welcome!

---

## 📝 Notes

- **Windows-specific**: Uses `windows.h` for `Sleep()` function and `system("cls")` for screen clearing
- **Data Persistence**: All inventory data is stored in `billing.txt`
- **Input Validation**: Limited error handling; entering invalid data may cause issues
- **Case Sensitivity**: Item names are case-sensitive when searching

---

## 👨‍💻 Author

Created as a learning project to demonstrate:

- Object-Oriented Programming in C++
- File I/O operations
- Modular code organization
- Basic inventory management system

---

## 📄 License

This project is open-source and available under the repository's license.

---

**Happy Coding! 🚀**
