#include "BillingOperations.h"

// Global inventory storage
std::vector<Bill> inventory;

// Utility: Clear input buffer
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Utility: Get valid integer input with validation
int getValidIntInput(const std::string& prompt, int minValue) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            if (value >= minValue) {
                clearInputBuffer();
                return value;
            } else {
                std::cout << "\tError: Value Must Be At Least " << minValue << std::endl;
            }
        } else {
            std::cout << "\tError: Please enter a valid number!" << std::endl;
            clearInputBuffer();
        }
    }
}

// Utility: Get valid string input (non-empty, supports spaces)
std::string getValidStringInput(const std::string& prompt) {
    std::string value;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, value);
        
        // Trim leading/trailing spaces
        size_t start = value.find_first_not_of(" \t\r\n");
        size_t end = value.find_last_not_of(" \t\r\n");
        
        if (start != std::string::npos && end != std::string::npos) {
            value = value.substr(start, end - start + 1);
            if (!value.empty()) {
                return value;
            }
        }
        std::cout << "\tError: Input Cannot Be Empty!" << std::endl;
    }
}

// Load inventory from file
void loadInventory() {
    std::ifstream in("billing.txt");
    if (!in) {
        std::cout << "\tNo existing inventory file found. Starting fresh." << std::endl;
        sleepMs(BillingConstants::SHORT_DELAY_MS);
        return;
    }

    std::string line;
    int itemCount = 0;
    
    while (std::getline(in, line)) {
        // Skip empty lines
        if (line.find_first_not_of(" \t\r\n") == std::string::npos) {
            continue;
        }

        std::stringstream ss(line);
        std::string itemName;
        int rate, quantity;
        char delimiter;

        // Parse format: "    itemName : rate : quantity"
        // First, skip leading whitespace and read until ':'
        std::string temp;
        if (std::getline(ss, temp, ':')) {
            // Trim the item name
            size_t start = temp.find_first_not_of(" \t");
            size_t end = temp.find_last_not_of(" \t");
            if (start != std::string::npos && end != std::string::npos) {
                itemName = temp.substr(start, end - start + 1);
            }

            // Read rate and quantity
            if (ss >> rate >> delimiter >> quantity) {
                Bill item;
                item.setItem(itemName);
                item.setRate(rate);
                item.setQuant(quantity);
                inventory.push_back(item);
                itemCount++;
            }
        }
    }
    
    in.close();
    std::cout << "\tLoaded " << itemCount << " items from inventory." << std::endl;
    sleepMs(2000);
}

// Save inventory to file
void saveInventory() {
    std::ofstream out("billing.txt");
    if (!out) {
        std::cout << "\tError: Cannot save inventory to file!" << std::endl;
        sleepMs(BillingConstants::MEDIUM_DELAY_MS);
        return;
    }

    for (const auto& item : inventory) {
        out << "\t" << item.getItem() << " : " << item.getRate() 
            << " : " << item.getQuant() << std::endl << std::endl;
    }

    out.close();
}

// Add item to inventory
void addItem() {
    Bill newItem;  // Create local Bill object as temporary container
    bool shouldClose = false;
    
    while (!shouldClose) {
        std::cout << "\t1.Add." << std::endl;
        std::cout << "\t2.Close." << std::endl;
        
        int menuChoice = getValidIntInput("\tEnter Choice: ", BillingConstants::MIN_CHOICE);

        if (menuChoice == 1) {
            CLEAR_SCREEN();
            
            std::string itemName = getValidStringInput("\tEnter Item Name: ");
            newItem.setItem(itemName);

            int itemRate = getValidIntInput("\tEnter Rate Of Item: ", BillingConstants::MIN_PRICE);
            newItem.setRate(itemRate);

            int itemQuantity = getValidIntInput("\tEnter Quantity Of Item: ", BillingConstants::MIN_QUANTITY);
            newItem.setQuant(itemQuantity);

            // Check if item already exists
            bool itemFound = false;
            for (auto& existingItem : inventory) {
                if (existingItem.getItem() == itemName) {
                    // Update quantity of existing item
                    existingItem.setQuant(existingItem.getQuant() + itemQuantity);
                    itemFound = true;
                    std::cout << "\tItem already exists. Quantity updated!" << std::endl;
                    break;
                }
            }

            if (!itemFound) {
                inventory.push_back(newItem);
                std::cout << "\tItem Added Successfully!" << std::endl;
            }
            
            saveInventory();
            sleepMs(BillingConstants::MEDIUM_DELAY_MS);
        } else if (menuChoice == 2) {
            CLEAR_SCREEN();
            shouldClose = true;
            std::cout << "\tBack To Main Menu!" << std::endl;
            sleepMs(BillingConstants::MEDIUM_DELAY_MS);
        } else {
            std::cout << "\tError: Enter a valid command (1 or 2)." << std::endl;
            sleepMs(BillingConstants::SHORT_DELAY_MS);
        }
    }
}

// Print bill
void printBill() {
    CLEAR_SCREEN();
    int totalAmount = 0;
    bool shouldClose = false;
    
    std::vector<std::pair<std::string, int>> billItems;  // Store (itemName, amount) pairs
    
    while (!shouldClose) {
        CLEAR_SCREEN();
        std::cout << "\t1.Add Bill." << std::endl;
        std::cout << "\t2.Close Session." << std::endl;
        
        int menuChoice = getValidIntInput("\tEnter Choice: ", BillingConstants::MIN_CHOICE);

        if (menuChoice == 1) {
            std::string requestedItem = getValidStringInput("\tEnter Item: ");
            int requestedQuantity = getValidIntInput("\tEnter Quantity: ", BillingConstants::MIN_QUANTITY);

            bool itemFound = false;

            for (auto& inventoryItem : inventory) {
                if (inventoryItem.getItem() == requestedItem) {
                    itemFound = true;
                    if (requestedQuantity <= inventoryItem.getQuant()) {
                        int lineAmount = inventoryItem.getRate() * requestedQuantity;
                        std::cout << "\n\t" << std::left 
                                  << std::setw(BillingConstants::ITEM_COLUMN_WIDTH) << "Item"
                                  << std::setw(BillingConstants::RATE_COLUMN_WIDTH) << "Rate"
                                  << std::setw(BillingConstants::QUANTITY_COLUMN_WIDTH) << "Quantity"
                                  << "Amount" << std::endl;
                        std::cout << "\t" << std::setw(BillingConstants::ITEM_COLUMN_WIDTH) << inventoryItem.getItem()
                                  << std::setw(BillingConstants::RATE_COLUMN_WIDTH) << inventoryItem.getRate()
                                  << std::setw(BillingConstants::QUANTITY_COLUMN_WIDTH) << requestedQuantity
                                  << lineAmount << std::endl;
                        
                        billItems.push_back({inventoryItem.getItem(), lineAmount});
                        inventoryItem.setQuant(inventoryItem.getQuant() - requestedQuantity);
                        totalAmount += lineAmount;
                    } else {
                        std::cout << "\tSorry, only " << inventoryItem.getQuant() 
                                  << " " << requestedItem << "(s) available!" << std::endl;
                    }
                    break;
                }
            }
            
            if (!itemFound) {
                std::cout << "\tItem Not Available!" << std::endl;
            }
        } else if (menuChoice == 2) {
            shouldClose = true;
            std::cout << "\tCounting Total Bill..." << std::endl;
        } else {
            std::cout << "\tError: Enter a valid command (1 or 2)." << std::endl;
        }
        
        sleepMs(BillingConstants::MEDIUM_DELAY_MS);
    }
    
    saveInventory();
    
    CLEAR_SCREEN();
    std::cout << std::endl << std::endl;
    std::cout << "\t========================================" << std::endl;
    std::cout << "\t         BILLING SUMMARY" << std::endl;
    std::cout << "\t========================================" << std::endl;
    
    if (!billItems.empty()) {
        std::cout << "\tItems Purchased:" << std::endl;
        for (const auto& item : billItems) {
            std::cout << "\t  - " << item.first << ": Rs. " << item.second << std::endl;
        }
        std::cout << "\t----------------------------------------" << std::endl;
    }
    
    std::cout << "\t Total Bill: Rs. " << totalAmount << std::endl;
    std::cout << "\t========================================" << std::endl;
    std::cout << "\tThanks For Shopping!" << std::endl << std::endl;
    sleepMs(BillingConstants::LONG_DELAY_MS);
}
