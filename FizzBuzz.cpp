// FizzBuzz kata:
// Write a function that receives and prints a passed in number.
// For multiples of 3 it prints "Fizz"
// For multiples of 5 it prints "Buzz"
// For multiples of both it prints "FizzBuzz"


# include <gtest/gtest.h>


std::string fizzBuzz(int value) {
    if(value % 3 == 0) return "Fizz";
    if(value == 5) return "Buzz";
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


TEST(FizzBuzzTest, returnsFizzWith3PassedIn) {
    checkFizzBuzz(3, "Fizz");
}


TEST(FizzBuzzTest, returnsBuzzWith5PassedIn) {
    checkFizzBuzz(5, "Buzz");
}


TEST(FizzBuzzTest, returnsFizzWith6PassedIn) {
    checkFizzBuzz(6, "Fizz");
}
