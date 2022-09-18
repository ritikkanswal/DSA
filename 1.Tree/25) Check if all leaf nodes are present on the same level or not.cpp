// https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1#


// Time complexity -> O(n)
// Space complexity -> O(h)
int prev = -1;
bool dfs(Node *root, int k)
{
    if (!root)
        return 1;

    if (!root->left and !root->right)
    {
        if (prev != -1 and prev != k)
            return 0;
        prev = k;
    }
    return dfs(root->left, k + 1) and dfs(root->right, k + 1);
}
bool check(Node *root)
{
    return dfs(root, 0);
}