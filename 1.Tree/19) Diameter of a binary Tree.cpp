// https://leetcode.com/problems/diameter-of-binary-tree/

//Method-1 (Time Complexity O(n^2))

int height(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
int diameterOfBinaryTree(TreeNode *root)
{
    if (!root)
        return 0;
    int l1 = height(root->left) + height(root->right);
    int l2 = diameterOfBinaryTree(root->left);
    int l3 = diameterOfBinaryTree(root->right);
    return max({l1, l2, l3});
}

//Method-2 (Time complexity - O(n))

int ma = 0;
int height(TreeNode *root)
{
    if (!root)
        return 0;
    int l1 = height(root->left);
    int l2 = height(root->right);
    int ans = l1 + l2;
    ma = max(ma, ans);
    return 1 + max(l1, l2);
}
int diameterOfBinaryTree(TreeNode *root)
{
    if (!root)
        return 0;
    height(root);
    return ma;
}