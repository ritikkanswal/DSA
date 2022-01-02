// https://leetcode.com/problems/binary-tree-preorder-traversal/
void preOrder(TreeNode *root, vector<int> &v)
{
    if (root)
    {
        v.push_back(root->val);
        preOrder(root->left, v);
        preOrder(root->right, v);
    }
}