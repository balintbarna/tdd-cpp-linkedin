// FizzBuzz kata:
// Write a function that receives and prints a passed in number.
// For multiples of 3 it prints "Fizz"
// For multiples of 5 it prints "Buzz"
// For multiples of both it prints "FizzBuzz"


# include <gtest/gtest.h>


std::string fizzBuzz(int value) {
    return "1";
}


TEST(FizzBuzzTest, returns1With1PassedIn) {
    std::string result = fizzBuzz(1);
    ASSERT_STREQ("1", result.c_str());
}
