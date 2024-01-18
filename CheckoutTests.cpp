#include <iostream>
#include <gtest/gtest.h>

#include "Checkout.hpp"


using namespace std;


class CheckoutTests : public ::testing::Test {
public:
protected:
    Checkout checkOut;
};


TEST_F(CheckoutTests, CanAddItemPrice) {
    checkOut.addItemPrice("a", 1);
}


TEST_F(CheckoutTests, CanAddItem) {
    checkOut.addItem("a");
}
