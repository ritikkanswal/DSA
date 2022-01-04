// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

// Method -1
map<int, int> mp;
int idx = 0;
TreeNode *create(vector<int> &pr, vector<int> &in, int l, int r)
{
    if (l > r)
        return NULL;

    TreeNode *root = new TreeNode(pr[idx++]);
    if (l == r)
        return root;
    int mid = mp[root->val];
    root->left = create(pr, in, l, mid - 1);
    root->right = create(pr, in, mid + 1, r);
    return root;
}
TreeNode *buildTree(vector<int> &pre, vector<int> &in)
{
    int n = pre.size();
    for (int i = 0; i < n; i++)
    {
        mp[in[i]] = i;
    }
    TreeNode *root = create(pre, in, 0, n - 1);
    return root;
}