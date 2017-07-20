class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> sums(nums.size()+1);
        for (auto i=1; i<sums.size(); i++)
            sums[i] = sums[i-1] + nums[i-1];
        int res = 0;
        vector<long> active;
        active.reserve(sums.size());
        for (int i=sums.size()-1; i>=0; i--) {
            auto lIter = lower_bound(active.begin(), active.end(), lower+sums[i]);
            auto uIter = upper_bound(active.begin(), active.end(), upper+sums[i]);
            res += distance(lIter, uIter);
            active.insert(lower_bound(active.begin(), active.end(), sums[i]), sums[i]);
        }
        return res;
    }
};
