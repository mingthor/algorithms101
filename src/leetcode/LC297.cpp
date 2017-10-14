#include "../../util/common.h"

int main()
{
    BinaryTree tree;
    TreeNode t1(1), t2(2), t3(3);
    t1.left = &t2;
    t1.right = &t3;
    string str = tree.serialize(&t1);
    cout<<str<<endl;
    TreeNode *root = tree.deserialize(str);
    string str2 = tree.serialize(root);
    cout<<str2<<endl;
    return 0;
}