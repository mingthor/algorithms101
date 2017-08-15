#include "../../util/common.h"

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int i=0, j=0;
        vector<pair<int, int>> res;
        while (res.size() < k) {
            if (res.empty())
                res.push_back(make_pair(nums1[i], nums2[j]));
            else {
                if (nums1[i+1] < nums2[j+1]) i++;
                else j++;
            }
        }
        return res;
    }
};

TEST(Solution, kSmallestPairs)
{
    vector<int> nums1({1,1,2});
    vector<int> nums2({1,2,3});
    vector<pair<int, int>> res = kSmallestPairs(nums1, nums2, 10);
    vector<pair<int, int>> expected({{1,1},{1,1}});
    ASSERT_EQ(res, expected);
}

int main()
{
    RunAllTests();
    return 0;
}