#include <iostream>
#include <gtest/gtest.h>

#include "Checkout.hpp"


using namespace std;


class CheckoutTests : public ::testing::Test {
public:
protected:
    Checkout checkOut;
};


TEST_F(CheckoutTests, CanCalculateTotal) {
    checkOut.addItemPrice("a", 1);
    checkOut.addItem("a");
    int total = checkOut.calculateTotal();
    ASSERT_EQ(1, total);
}
