#include "../../util/common.h"
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        vector<int> dp = costs[0];
        for (int i=1; i<costs.size(); i++) {
            int m1=INT_MAX, m2=INT_MAX;
            for (int j=0; j<dp.size(); j++) {
                if (dp[j] <= m1) {
                    m2 = m1;
                    m1 = dp[j];
                } else if (dp[j] < m2) m2 = dp[j];
            }

            for (int j=0; j<dp.size(); j++) {
                dp[j] = (m1 == dp[j]) ? (m2+costs[i][j]) : (m1+costs[i][j]);
            }
        }
        int res = INT_MAX;
        for (auto c : dp) res = min(res, c);
        return res;
    }
};

TEST(Solution, minCost2)
{
    vector<vector<int>> costs({{1,2,3}, {1,1,1}});
    int res = minCostII(costs);
    ASSERT_EQ(res, 2);
}

int main()
{
    RunAllTests();
    return 0;
}