#include "../../util/common.h"

class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        if (!root) return res;
        inorder(root, res);
        int start = 0; 
        double m = INT_MAX;
        for (int i=0; i+k<=res.size(); i++) {
            double d = max(abs(res[i]-target) , abs(res[i+k-1]-target));
            if (d < m) {
                m = d;
                start = i;
            }
        }
        return vector<int>(res.begin()+start, res.begin()+start+k);
    }
    void inorder(TreeNode* node, vector<int> &seq) {
        if (!node) return;
        inorder(node->left, seq);
        seq.push_back(node->val);
        inorder(node->right, seq);
    }
};

int main()
{
    Solution sol;
    TreeNode zero(0), one(1), n1(-1), n2(-2);
    zero.left = &n2;
    zero.right = &one;
    n2.right = &n1;
    vector<int> res = sol.closestKValues(&zero, 0.0, 3);
    cout<<res<<endl;
    return 0;
}