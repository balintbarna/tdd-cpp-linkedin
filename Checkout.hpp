#pragma once

#include <string>


class Checkout {
public:
    Checkout() {}
    void addItemPrice(std::string item, int price) {}
    void addItem(std::string item) {}
    int calculateTotal() {
        return 1;
    }
};
