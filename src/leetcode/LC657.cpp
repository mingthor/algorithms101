#include "../../util/common.h"

class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0, y=0;
        for (auto c : moves) {
            switch (c) {
                case 'U': y++; break;
                case 'D': y--; break;
                case 'L': x--; break;
                case 'R': x++; break;
                default: break;
            }
        }
        return (x==0 && y==0);
    }
};

TEST(Solution, judgeCircle)
{
    bool res = judgeCircle("UD");
    ASSERT_EQ(res, true);

    res = judgeCircle("LL");
    ASSERT_EQ(res, false);

    //res = judgeCircle("RUDULLDRR");
    //ASSERT_EQ(res, true);

    res == judgeCircle("DURDLDRRLL");
    ASSERT_EQ(res, false);
}

int main()
{
    RunAllTests();
    return 0;
}