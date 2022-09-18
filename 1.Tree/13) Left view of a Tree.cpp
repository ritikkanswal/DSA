// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

// Time Complexity : O(n)
// Space Complexity : O(h)
void dfs(Node *root, int level, vector<int> &res)
{
    if (!root)
        return;
    if (level >= res.size())
        res.push_back(root->data);
    dfs(root->left, level + 1, res);
    dfs(root->right, level + 1, res);
}
vector<int> leftView(Node *root)
{
    vector<int> res;
    dfs(root, 0, res);
    return res;
}

// Approach 2
// Time Complexity : O(n)
// Space Complexity : O(n) or O(2^h)
// Note: Maximum queue size would be 2^h, but 2^h is nearly equivalent to O(n)
// For skewed tree, maximum queue size would be o(1) (considering it to be the best case)
vector<int> leftView(Node *root)
{
    if (!root)
        return {};

    queue<Node *> q;
    q.push(root);
    vector<int> v;

    while (q.empty() == false)
    {
        int qu = q.size();
        for (int i = 0; i < qu; i++)
        {
            Node *tmp = q.front();
            q.pop();
            if (i == 0)
                v.push_back(tmp->data);

            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
        }
    }
    return v;
}