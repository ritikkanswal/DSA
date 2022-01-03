// https://leetcode.com/problems/binary-tree-right-side-view/

//Method-1
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

//Method-2

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