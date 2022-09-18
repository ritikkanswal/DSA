// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

// Method 1
// Given same node be ancestor of itself or not (otherwise confirm from interviewer)
// Time complexity -> O(n)
// Space complexity -> O(n)


vector<TreeNode *> find_path(TreeNode *root, vector<TreeNode *> p, TreeNode *x)
{
    if (!root)
        return {};
    p.push_back(root);
    if (root == x)
        return p;
    vector<TreeNode *> p1 = find_path(root->left, p, x);
    vector<TreeNode *> p2 = find_path(root->right, p, x);
    return p1.size() > p2.size() ? p1 : p2;
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    vector<TreeNode *> p1, p2;
    p1 = find_path(root, p1, p);
    p2 = find_path(root, p2, q);
    int n = min(p1.size(), p2.size());
    for (int i = 0; i < n; i++)
    {
        if (p1[i]->val != p2[i]->val)
            return p1[i - 1];
    }
    return p1[n - 1];
}
// Method 2
// Time complexity -> O(n)
// Space complexity -> O(h)
TreeNode *lca(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root)
        return nullptr;

    if (root == p || root == q)
        return root;

    TreeNode *Left = lca(root->left, p, q);
    TreeNode *Right = lca(root->right, p, q);

    if (Left != NULL and Right != NULL)
        return root;

    if (Left != NULL)
        return Left;
    else
        return Right;
}
