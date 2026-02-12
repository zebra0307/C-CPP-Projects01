#include "Bill.h"

Bill::Bill() : Item(""), Rate(0), Quantity(0) {}

void Bill::setItem(const std::string& item) {
    Item = item;
}

void Bill::setRate(int rate) {
    Rate = rate;
}

void Bill::setQuant(int quant) {
    Quantity = quant;
}

const std::string& Bill::getItem() const {
    return Item;
}

int Bill::getRate() const {
    return Rate;
}

int Bill::getQuant() const {
    return Quantity;
}
