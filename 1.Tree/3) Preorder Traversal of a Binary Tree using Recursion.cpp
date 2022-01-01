// https://leetcode.com/problems/binary-tree-postorder-traversal
vector<int> postorderTraversal(TreeNode *root)
{
    if (!root)
        return {};
    stack<TreeNode *> st;
    st.push(root);
    vector<int> res;
    while (!st.empty())
    {
        TreeNode *curr = st.top();
        if (!curr->left and !curr->right)
        {
            res.push_back(curr->val);
            st.pop();
        }
        else if (curr->right)
        {
            st.push(curr->right);
            curr->right = NULL;
        }
        if (curr->left)
        {
            st.push(curr->left);
            curr->left = NULL;
        }
    }
    return res;
}