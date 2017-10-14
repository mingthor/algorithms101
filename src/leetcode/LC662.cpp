/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include "../../util/common.h"

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        deque<TreeNode*> dq;
        dq.push_back(root);
        int res = 0;
        while (!dq.empty()) {
            int nlev = dq.size();
            res = max(res, nlev);
            for (int i=0; i<nlev; i++) {
                TreeNode* node = dq.front();
                dq.pop_front();
                if (node) {
                    dq.push_back(node->left);
                    dq.push_back(node->right);
                } else {
                    dq.push_back(0);
                    dq.push_back(0);
                }
            }
            while (!dq.empty() && !dq.front()) dq.pop_front();
            while (!dq.empty() && !dq.back()) dq.pop_back();
        }
        return res;
    }
};

TEST(Solution, widthOfBinaryTree)
{
    TreeNode one(1), two(2), three(3), four(4), five(5), six(6), seven(7);
    one.left = &two;
    one.right = &three;
    two.left = &four;
    three.right = &five;
    four.left = &six;
    five.right = &seven;
    int res = widthOfBinaryTree(&one);
    ASSERT_EQ(res, 8);
}

int main()
{
    RunAllTests();
    return 0;
}