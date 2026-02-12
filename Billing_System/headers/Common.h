#ifndef COMMON_H
#define COMMON_H

// C++ standard library headers
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>
#include <thread>
#include <chrono>
#include <iomanip>

// Cross-platform utilities
#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_SCREEN() system("cls")
#else
    #define CLEAR_SCREEN() system("clear")
#endif

// Cross-platform sleep function
inline void sleepMs(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

// Named constants for better code readability (eliminates magic numbers)
namespace BillingConstants {
    // Sleep/delay durations (in milliseconds)
    constexpr int SHORT_DELAY_MS = 2000;
    constexpr int MEDIUM_DELAY_MS = 3000;
    constexpr int LONG_DELAY_MS = 5000;
    
    // Bill display column widths
    constexpr int ITEM_COLUMN_WIDTH = 25;
    constexpr int RATE_COLUMN_WIDTH = 10;
    constexpr int QUANTITY_COLUMN_WIDTH = 12;
    
    // Minimum input values
    constexpr int MIN_CHOICE = 1;
    constexpr int MIN_PRICE = 1;
    constexpr int MIN_QUANTITY = 1;
}

#endif
