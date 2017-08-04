#include "../util/testharness.h"
#include "../util/prettyprint.h"
#include <iostream>
#include <unordered_map>
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

    std::vector<int> foo({1,2,3}); 
    std::cout << "My vector: " << foo << std::endl;
    std::unordered_map<int, string> dict({{1,"a"},{2,"bc"},{3,"test"}});
    std::cout<< "My map: " << dict <<std::endl;
    return 0;
}