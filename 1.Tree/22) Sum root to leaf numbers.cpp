// https://leetcode.com/problems/sum-root-to-leaf-numbers/

// Time complexity -> O(n)
// Space complexity -> O(h)

int res = 0;
void dfs(TreeNode *root, int val)
{
    if (!root)
        return;

    if (!root->left and !root->right)
    {
        res += val * 10 + root->val;
        return;
    }

    val = val * 10 + root->val;

    dfs(root->left, val);
    dfs(root->right, val);
}
int sumNumbers(TreeNode *root)
{
    dfs(root, 0);
    return res;
}