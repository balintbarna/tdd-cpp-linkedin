#pragma once

#include <string>
#include <map>


class Checkout {
public:
    Checkout() {}
    void addItemPrice(std::string item, int price) {
        prices[item] = price;
    }

    void addItem(std::string item) {
        total += prices[item];
    }

    int calculateTotal() {
        return total;
    }

private:
    std::map<std::string, int> prices;
    int total = 0;
};
