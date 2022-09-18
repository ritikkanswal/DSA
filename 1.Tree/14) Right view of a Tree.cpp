// https://leetcode.com/problems/binary-tree-right-side-view/

// Method-1
// Time Complexity : O(n)
// Space Complexity : O(h)
void dfs(TreeNode *root, vector<int> &res, int level)
{
    if (root == NULL)
        return;
    if (level >= res.size())
        res.push_back(root->val);
    dfs(root->right, res, level + 1);
    dfs(root->left, res, level + 1);
}
vector<int> rightSideView(TreeNode *root)
{
    vector<int> res;
    dfs(root, res, 0);
    return res;
}

// Method-2
// Time Complexity : O(n)
// Space Complexity : O(n) or O(2^h)
// Note: Maximum queue size would be 2^h, but 2^h is nearly equivalent to O(n)
// For skewed tree, maximum queue size would be o(1) (considering it to be the best case)
vector<int> rightSideView(TreeNode *root)
{
    if (!root)
        return {};
    queue<TreeNode *> q;
    q.push(root);
    vector<int> res;
    while (!q.empty())
    {
        int val;
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *root = q.front();
            q.pop();
            val = root->val;
            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }
        res.push_back(val);
    }
    return res;
}