#include "../../util/common.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool checkEqualTree(TreeNode* root) {
        if (!root) return false;
        sum(root);
        return checkEqual(root, root->val);
    }

    bool checkEqual(TreeNode* root, int s) {
        if (!root) return false;
        if (root->left && s == 2*root->left->val)
            return true;
        else if (root->right && s == 2*root->right->val)
            return true;

        if (checkEqual(root->left, s)) return true;
        if (checkEqual(root->right, s)) return true;
        return false;
    }
    void sum(TreeNode* root) {
        if (!root) return;
        int s = 0;
        if (root->left) {
            sum(root->left);
            s += root->left->val;
        }
        if (root->right) {
            sum(root->right);
            s += root->right->val;
        }
        root->val += s;
    }
};

TEST(Solution, checkEqualTree)
{
    TreeNode one(5), two(10), three(10), four(2), five(3);
    one.left = &two;
    one.right = &three;
    three.left = &four;
    three.right = &five;
    bool res = checkEqualTree(&one);
    ASSERT_EQ(res, true);
}

int main()
{
    RunAllTests();
    return 0;
}