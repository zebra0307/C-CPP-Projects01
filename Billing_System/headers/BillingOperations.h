#ifndef BILLING_OPERATIONS_H
#define BILLING_OPERATIONS_H

#include "Common.h"
#include "Bill.h"

// Global inventory storage
extern std::vector<Bill> inventory;

// Function declarations
void loadInventory();
void saveInventory();
void addItem();
void printBill();

// Utility functions
int getValidIntInput(const std::string& prompt, int minValue = 0);
std::string getValidStringInput(const std::string& prompt);
void clearInputBuffer();

#endif
