#include "../../util/common.h"
/// LinkedIn Onsite interview question
/// Given a binary tree, first, print the leaf nodes. Then, print the
/// next level leaf nodes as if the previous leaf nodes have been removed, ...

int labelNode(TreeNode* root, map<int, vector<int>>& leaves) {
    if (!root) return 0;
    int lLabel = labelNode(root->left, leaves);
    int rLabel = labelNode(root->right, leaves);
    int label = max(lLabel, rLabel) + 1;
    leaves[label].push_back(root->val);
    return label;
}

void printLeavesByLevel(TreeNode* root) {
    map<int, vector<int>> leaves;
    labelNode(root, leaves);
    for (auto level : leaves) {
        cout<<level<<endl;
    }
}

int main()
{
    TreeNode* root = BinaryTree::deserialize("9 10 5 4 # # 3 # # 6 # # 8 7 2 # # # 11 # #");
    string preorder = BinaryTree::serialize(root);
    cout<<preorder<<endl;
    cout<<"***********************"<<endl;
    printLeavesByLevel(root);
    return 0;
}