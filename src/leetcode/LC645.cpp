class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // swap number k with the element at position k-1
        // util the two are equal
        for (auto& k : nums) {
            while (k != nums[k-1]) swap(k, nums[k-1]);
        }
        
        // the number n whose index is not n-1 is the duplicate
        // its position should hold the missing number, which should be i+1
        for (int i=0; i<(int)nums.size(); i++) {
            if (nums[i] != i+1) return {nums[i], i+1};
        }
        return {};
    }
};
