//https://leetcode.com/problems/binary-tree-inorder-traversal/
vector<int>v;
vector<int> inorderTraversal(TreeNode *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        v.push_back(root->val);
        inorderTraversal(root->right);
    }
    return v;
}