class Solution {
public:
    //! Binary Indexed Tree solution
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        if (nums.size() <= 1) return res;
        auto p = minmax_element(nums.begin(), nums.end());
        int offset = 1-*p.first;
        unordered_map<int, int> bitree;
        for (int i=(int)nums.size()-1; i>=0; i--) {
            int idx = nums[i]+offset;
            // update
            while (idx <= *p.second+offset) {
                bitree[idx]++;
                idx += (idx & -idx);
            }
            
            // sum
            idx = nums[i]+offset-1;
            int sum = 0;
            while (idx > 0) {
                sum += bitree[idx];
                idx -= (idx & -idx);
            }
            res[i] = sum;
        }
        return res;
    }
};
