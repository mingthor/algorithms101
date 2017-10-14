#include "../../util/common.h"

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(nums, 0, res);
        return res;
    }
    void helper(vector<int>& nums, int start, vector<vector<int>> &res) {
        if (start == nums.size()) res.push_back(nums);
        for (int i=start; i<nums.size(); i++) {
            swap(nums[start], nums[i]);
            helper(nums, start+1, res);
            swap(nums[start], nums[i]);
        }
    }
};

int main()
{
    vector<int> nums({1,2,3});
    Solution sol;
    vector<vector<int>> res = sol.permute(nums);
    cout<<res<<endl;
    return 0;
}