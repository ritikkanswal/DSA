// https://leetcode.com/problems/subtree-of-another-tree/
bool isIdentical(TreeNode *root, TreeNode *subRoot)
{
    if (root == NULL and subRoot == NULL)
        return true;
    if (root == NULL or subRoot == NULL)
        return false;

    if (root->val == subRoot->val and isIdentical(root->left, subRoot->left) and isIdentical(root->right, subRoot->right))
        return true;
    return false;
}
bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    if (subRoot == NULL)
        return true;
    if (root == NULL)
        return false;

    if (isIdentical(root, subRoot))
        return true;

    return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
}