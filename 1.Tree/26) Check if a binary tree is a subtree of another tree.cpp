// https://leetcode.com/problems/subtree-of-another-tree/

//Method 1 O(n^2) Solution
bool isIdentical(TreeNode *root, TreeNode *subroot)
{
    if (root == NULL and subroot == NULL)
        return 1;
    if (root == NULL and subroot != NULL)
        return 0;
    if (root != NULL and subroot == NULL)
        return 0;

    if (root->val != subroot->val)
        return 0;
    return (isIdentical(root->left, subroot->left) and
            isIdentical(root->right, subroot->right));
}
bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    if (root == NULL and subRoot != NULL)
        return 0;
    if (root == NULL and subRoot == NULL)
        return 1;

    if (isIdentical(root, subRoot))
        return true;

    return (isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot));
}

//Method 2 O(N) solution

void StoreInorder(TreeNode *root, string &s)
{
    if (root == NULL)
    {
        s += '%';
        return;
    }
    StoreInorder(root->left, s);
    s += root->val + '0';
    StoreInorder(root->right, s);
}
void StorePreorder(TreeNode *root, string &s)
{
    if (root == NULL)
    {
        s += '%';
        return;
    }
    s += root->val + '0';
    StorePreorder(root->left, s);
    StorePreorder(root->right, s);
}
bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    if (subRoot == NULL)
        return true;
    if (root == NULL)
        return false;
    string s1, s2, s3, s4;
    StoreInorder(root, s1);
    StoreInorder(subRoot, s2);
    StorePreorder(root, s3);
    StorePreorder(subRoot, s4);

    if (s1.find(s2) != std::string::npos)
    {
        if (s3.find(s4) != std::string::npos)
        {
            return true;
        }
    }
    return false;
}