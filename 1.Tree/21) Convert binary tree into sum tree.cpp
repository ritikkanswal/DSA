// https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1#
int dfs(Node *root)
{
    if (!root)
        return 0;
    int Left = dfs(root->left);
    int Right = dfs(root->right);
    int Root = root->data;
    root->data = Left + Right;
    return Left + Right + Root;
}
void toSumTree(Node *node)
{
    dfs(node);
}