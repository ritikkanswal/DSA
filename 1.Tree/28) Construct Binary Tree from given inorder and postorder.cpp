// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
map<int, int> mp;
int idx = 0;
TreeNode *create(vector<int> &in, vector<int> &po, int l, int r)
{
    if (l > r)
        return NULL;

    TreeNode *root = new TreeNode(po[idx--]);
    if (l == r)
        return root;
    int mid = mp[root->val];
    root->right = create(in, po, mid + 1, r);
    root->left = create(in, po, l, mid - 1);

    return root;
}
TreeNode *buildTree(vector<int> &in, vector<int> &po)
{
    int n = in.size();
    for (int i = 0; i < n; i++)
    {
        mp[in[i]] = i;
    }
    idx = n - 1;
    TreeNode *root = create(in, po, 0, n - 1);
    return root;
}