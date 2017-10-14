#include "../../util/common.h"

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size());
    }
    TreeNode* sortedArrayToBST(vector<int>& nums, int s, int e) {
        if (s >= e) return 0;
        int mid = (s + e) / 2;
        TreeNode* left = sortedArrayToBST(nums, s, mid);
        TreeNode* right = sortedArrayToBST(nums, mid+1, e);
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = left;
        root->right = right;
        return root;
    }
};

TEST(Solution, sortedArrayToBST)
{
    vector<int> nums({1,2,3,4});
    TreeNode* root = sortedArrayToBST(nums);
    ASSERT_NE(root, (void *)0);
}
int main()
{
    RunAllTests();
    return 0;
}