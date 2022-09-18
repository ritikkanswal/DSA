//https://leetcode.com/problems/binary-tree-inorder-traversal/
// Time Complexity : O(n)
//Space Complexity : O(n)
vector<int> inorderTraversal(TreeNode *root)
{
    if (!root)
        return {};
    stack<TreeNode *> st;
    st.push(root);
    vector<int> res;
    while (!st.empty())
    {
        TreeNode *curr = st.top();
        if (curr->left)
        {
            st.push(curr->left);
            curr->left = NULL;
        }
        else
        {
            res.push_back(curr->val);
            st.pop();
            if (curr->right)
                st.push(curr->right);
        }
    }
    return res;
}

