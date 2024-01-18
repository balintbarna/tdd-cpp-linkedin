#pragma once

#include <string>
#include <map>


class Checkout {
public:
    Checkout() {}
    void addItemPrice(std::string name, int price) {
        prices[name] = price;
    }

    void addItem(std::string name) {
        if (prices.find(name) == prices.end()) throw std::invalid_argument("Item has no price.");
        basket[name]++;
    }

    int calculateTotal() {
        int total = 0;
        for (auto &x : basket) {
            total += getPrice(x.first, x.second);
        }
        return total;
    }

    void addDiscount(std::string name, int numItems, int discountPrice) {
        Discount discount{numItems, discountPrice};
        discounts[name] = discount;
    }

private:
    struct Discount {
        int numItems;
        int discountPrice;
    };
    std::map<std::string, Discount> discounts;
    std::map<std::string, int> prices;
    std::map<std::string, int> basket;

    int getPrice(const std::string name, const int numItems) {
        auto discount = discounts[name];
        int numDiscount = discount.numItems ? numItems / discount.numItems : 0;
        int rest = numItems - numDiscount * discount.numItems;
        return numDiscount * discount.discountPrice + rest * prices[name];
    }
};
