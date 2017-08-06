#include "../../util/common.h"
 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* n = s.top();
            res.push_back(n->val);
            s.pop();
            if (n->right) s.push(n->right);
            if (n->left) s.push(n->left);
        }
        return res;
    }
};

TEST(Solution, preorder)
{
    TreeNode one(1), two(2), three(3);
    one.right = &two;
    two.left = &three;
    vector<int> res = preorderTraversal(&one);
    vector<int> expected({1,2,3});
    ASSERT_EQ(res, expected);
    
    TreeNode four(4), five(5);
    one.left = &four;
    four.right = &five;
    res = preorderTraversal(&one);
    expected = {1,4,5,2,3};
    ASSERT_EQ(res, expected);
}

int main()
{
    RunAllTests();
    return 0;
}