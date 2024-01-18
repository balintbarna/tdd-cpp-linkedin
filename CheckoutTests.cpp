#include <iostream>
#include <gtest/gtest.h>

#include "Checkout.hpp"


using namespace std;


TEST(CheckoutTests, CanAddItemPrice) {
    Checkout co;
    co.addItemPrice("a", 1);
}


TEST(CheckoutTests, CanAddItem) {
    Checkout co;
    co.addItem("a");
}
