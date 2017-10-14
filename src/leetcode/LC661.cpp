#include "../../util/common.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> res(M.size(), vector<int>(M[0].size()));
        int d[] = {-1, 0, 1};
        for (int i=0; i<M.size(); i++) {
            for (int j=0; j<M[i].size(); j++) {
                int sum = 0, cnt = 0;
                for (auto dx : d) {
                    for (auto dy : d) {
                        if (i+dx<0 || i+dx>=(int)M.size()) continue;
                        if (j+dy<0 || j+dy>=(int)M[i].size()) continue;
                        sum += M[i+dx][j+dy];
                        cnt += 1;
                    }
                }
                res[i][j] = sum / cnt;
            }
        }
        return res;
    }
};

TEST(Solution, imageSmoother)
{
    vector<vector<int>> M({{1,1,1},{1,0,1},{1,1,1}});
    vector<vector<int>> res = imageSmoother(M);
    vector<vector<int>> expected({{0,0,0},{0,0,0},{0,0,0}});
    ASSERT_EQ(res, expected);
}
int main()
{
    RunAllTests();
    return 0;
}