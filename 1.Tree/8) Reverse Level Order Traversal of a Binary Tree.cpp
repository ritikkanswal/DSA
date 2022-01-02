// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

// APPROACH-1 (using Reverse())
vector<vector<int>> levelOrderBottom(TreeNode *root)
{
    if (!root)
        return {};
    queue<TreeNode *> q;
    q.push(root);
    vector<vector<int>> res;
    while (!q.empty())
    {
        vector<int> v;
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *root = q.front();
            q.pop();
            v.push_back(root->val);
            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }
        res.push_back(v);
    }
    reverse(res.begin(), res.end());
    return res;
}

// APPROACH-2 (using Stack)
vector<vector<int>> levelOrderBottom(TreeNode *root)
{
    if (!root)
        return {};
    queue<TreeNode *> q;
    stack<vector<int>> st;
    q.push(root);
    vector<vector<int>> res;
    while (!q.empty())
    {
        vector<int> v;
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *root = q.front();
            q.pop();
            v.push_back(root->val);
            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }
        st.push(v);
    }
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
    return res;
}

// APPROACH-3 (By first calculating number of Levels)

int dfs(TreeNode *root)
{
    if (!root)
        return 0;
    return max(dfs(root->left), dfs(root->right)) + 1;
}
vector<vector<int>> levelOrderBottom(TreeNode *root)
{
    if (!root)
        return {};
    queue<TreeNode *> q;
    q.push(root);
    int k = dfs(root);
    vector<vector<int>> res(k, {vector<int>({})});
    k--;
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *root = q.front();
            q.pop();
            res[k].push_back(root->val);
            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }
        k--;
    }
    return res;
}