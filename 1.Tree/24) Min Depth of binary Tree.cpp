// https://leetcode.com/problems/minimum-depth-of-binary-tree/
int mi = INT_MAX;
void dfs(TreeNode *root, int k)
{
    if (!root)
        return;
    if (!root->left and !root->right)
    {
        mi = min(mi, k);
        return;
    }
    dfs(root->left, k + 1);
    dfs(root->right, k + 1);
}
int minDepth(TreeNode *root)
{
    if (!root)
        return 0;
    dfs(root, 1);
    return mi;
}