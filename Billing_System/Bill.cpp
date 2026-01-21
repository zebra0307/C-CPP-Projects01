#include "headers/Bill.h"

Bill::Bill() : Item(""), Rate(0), Quantity(0) {}

void Bill::setItem(string item) {
    Item = item;
}

void Bill::setRate(int rate) {
    Rate = rate;
}

void Bill::setQuant(int quant) {
    Quantity = quant;
}

string Bill::getItem() {
    return Item;
}

int Bill::getRate() {
    return Rate;
}

int Bill::getQuant() {
    return Quantity;
}
