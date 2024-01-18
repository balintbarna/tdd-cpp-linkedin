// FizzBuzz kata:
// Write a function that receives and prints a passed in number.
// For multiples of 3 it prints "Fizz"
// For multiples of 5 it prints "Buzz"
// For multiples of both it prints "FizzBuzz"


# include <gtest/gtest.h>


std::string fizzBuzz(int value) {
    return std::to_string(value);
}


void checkFizzBuzz(int value, std::string expected) {
    auto result = fizzBuzz(value);
    ASSERT_STREQ(expected.c_str(), result.c_str());
}


TEST(FizzBuzzTest, returns1With1PassedIn) {
    checkFizzBuzz(1, "1");
}


TEST(FizzBuzzTest, returns2With2PassedIn) {
    checkFizzBuzz(2, "2");
}
