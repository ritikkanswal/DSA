// https://leetcode.com/problems/cousins-in-binary-tree/

// Method-1
// Time Complexity : O(n)
// Space Complexity : O(h)
bool is_siblings(TreeNode *root, int x, int y)
{
    if (!root)
        return 0;
    if (root->left and root->right)
    {
        if (root->left->val == x and root->right->val == y)
            return 1;
        if (root->left->val == y and root->right->val == x)
            return 1;
    }
    return is_siblings(root->left, x, y) or is_siblings(root->right, x, y);
}
int level(TreeNode *root, int val, int k)
{
    if (!root)
        return 0;

    if (root->val == val)
        return k;

    return max(level(root->left, val, k + 1), level(root->right, val, k + 1));
}
bool isCousins(TreeNode *root, int x, int y)
{
    return level(root, x, 0) == level(root, y, 0) and !(is_siblings(root, x, y));
}

//Method 2
// Time Complexity : O(n)
// Space Complexity : O(n) or O(2^h)
// Note: Maximum queue size would be 2^h, but 2^h is nearly equivalent to O(n)
// For skewed tree, maximum queue size would be o(1) (considering it to be the best case)
bool isCousins(TreeNode *root, int x, int y)
{
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        bool isXexist = 0, isYexist = 0;
        for (int i = 0; i < n; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            if (curr->left and curr->right)
            {
                if (curr->left->val == x and curr->right->val == y)
                    return false;
                if (curr->left->val == y and curr->right->val == x)
                    return false;
            }
            if (curr->val == x)
                isXexist = 1;
            if (curr->val == y)
                isYexist = 1;
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        if (isXexist and isYexist)
            return 1;
    }
    return 0;
}