#ifndef BILL_H
#define BILL_H

#include "Common.h"

class Bill {
private:
    string Item;
    int Rate, Quantity;

public:
    Bill();
    
    void setItem(string item);
    void setRate(int rate);
    void setQuant(int quant);
    
    string getItem();
    int getRate();
    int getQuant();
};

#endif
