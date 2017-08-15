#include "../../util/common.h"

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        if (nums.empty()) return false;
        queue<int> q;
        int pcount = 0, prev = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > prev+1) {
                while (!q.empty()) {
                    if (prev - q.front() < 2) return false;
                    q.pop();
                }
                pcount = 0;
            }
            // count the number of same elements
            int cnt = 1;
            while (i+1<nums.size() && nums[i]==nums[i+1]) {
                i++;
                cnt++;
            }
            int d = cnt - pcount;
            while (d) {
                if (d > 0) {
                    // record start of new sequence
                    q.push(nums[i]);
                    d--;
                } else {
                    // end of sequence
                    if (prev - q.front() < 2) return false;
                    q.pop();
                    d++;
                }
            }
            pcount = cnt;
            prev = nums[i];
        }
        while (!q.empty()) {
            if (prev - q.front() < 2) return false;
            q.pop();
        }
        return true;
    }
};

TEST(Solution, isPossible)
{
    vector<int> nums({1,2,3,3,4,5});
    bool res = isPossible(nums);
    ASSERT_EQ(res, true);

    nums = {1,2,3,3,4,4,5,5};
    res = isPossible(nums);
    ASSERT_EQ(res, true);

    nums = {1,2,3,4,4,5};
    res = isPossible(nums);
    ASSERT_EQ(res, false);

    nums = {1,2,2,3,3,3,4,4,5};
    res = isPossible(nums);
    ASSERT_EQ(res, true);

    nums = {1,2,2,3,3,3,4,4,4,5};
    res = isPossible(nums);
    ASSERT_EQ(res, true);

    nums = {1,2,2,3,3,3,4,4,4,5,7,8,8,9,9,10};
    res = isPossible(nums);
    ASSERT_EQ(res, true);
}

int main()
{
    RunAllTests();
    return 0;
}