#include "Common.h"
#include "Bill.h"
#include "BillingOperations.h"

int main() {
    // Load inventory at startup
    CLEAR_SCREEN();
    std::cout << "\tInitializing Billing System..." << std::endl;
    loadInventory();
    
    bool shouldExit = false;
    while (!shouldExit) {
        CLEAR_SCREEN();

        std::cout << "\tWelcome To Super Market Billing System" << std::endl;
        std::cout << "\t**************************************" << std::endl;
        std::cout << "\t\t1.Add Item." << std::endl;
        std::cout << "\t\t2.Print Bill." << std::endl;
        std::cout << "\t\t3.Exit." << std::endl;
        
        int userChoice = getValidIntInput("\t\tEnter Choice: ", BillingConstants::MIN_CHOICE);

        if (userChoice == 1) {
            CLEAR_SCREEN();
            addItem();
            sleepMs(BillingConstants::MEDIUM_DELAY_MS);
        }
        else if (userChoice == 2) {
            printBill();
        }
        else if (userChoice == 3) {
            CLEAR_SCREEN();
            shouldExit = true;
            std::cout << "\tSaving inventory..." << std::endl;
            saveInventory();
            std::cout << "\tGood Luck!" << std::endl;
            sleepMs(BillingConstants::MEDIUM_DELAY_MS);
        }
        else {
            std::cout << "\tError: Please enter 1, 2, or 3." << std::endl;
            sleepMs(BillingConstants::SHORT_DELAY_MS);
        }
    }

    return 0;
}