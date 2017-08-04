#include "../util/testharness.h"
#include <iostream>
using namespace std;

class HelloTest 
{

};

TEST(HelloTest, dummy)
{
    ASSERT_TRUE(true);
    ASSERT_EQ(3, 3);
}
int main()
{
    RunAllTests();
    return 0;
}