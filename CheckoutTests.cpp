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


TEST_F(CheckoutTests, CanTotalForMultipleItems) {
    checkOut.addItemPrice("a", 1);
    checkOut.addItemPrice("b", 2);
    checkOut.addItem("a");
    checkOut.addItem("b");
    int total = checkOut.calculateTotal();
    ASSERT_EQ(3, total);
}


TEST_F(CheckoutTests, CanAddDiscount) {
    checkOut.addDiscount("a", 3, 2);
}


TEST_F(CheckoutTests, CanTotalWithDiscount) {
    checkOut.addItemPrice("a", 1);
    checkOut.addDiscount("a", 3, 2);
    checkOut.addItem("a");
    checkOut.addItem("a");
    checkOut.addItem("a");
    int total = checkOut.calculateTotal();
    ASSERT_EQ(2, total);
    checkOut.addItem("a");
    total = checkOut.calculateTotal();
    ASSERT_EQ(3, total);
    checkOut.addItem("a");
    total = checkOut.calculateTotal();
    ASSERT_EQ(4, total);
    checkOut.addItem("a");
    total = checkOut.calculateTotal();
    ASSERT_EQ(4, total);
}


TEST_F(CheckoutTests, ThrowsOnAddedItemWithoutPrice) {
    ASSERT_THROW(checkOut.addItem("a"), std::invalid_argument);
    checkOut.addItemPrice("a", 1);
    ASSERT_NO_THROW(checkOut.addItem("a"));
}
