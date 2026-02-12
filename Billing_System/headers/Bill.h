#ifndef BILL_H
#define BILL_H

#include "Common.h"

class Bill {
private:
    std::string Item;
    int Rate, Quantity;

public:
    Bill();
    
    void setItem(const std::string& item);
    void setRate(int rate);
    void setQuant(int quant);
    
    const std::string& getItem() const;
    int getRate() const;
    int getQuant() const;
};

#endif
