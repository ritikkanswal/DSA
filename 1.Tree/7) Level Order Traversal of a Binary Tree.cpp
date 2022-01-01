//  https://leetcode.com/problems/binary-tree-level-order-traversal/
 vector<vector<int>> levelOrder(TreeNode* root) {
    if(!root) return {};
    queue<TreeNode *>q;
    q.push(root);
    vector<vector<int>>res;
    while(!q.empty())
    {
        vector<int>v;
        int n=q.size();
        for(int i=0;i<n;i++)
        {
                TreeNode *root=q.front();
                q.pop();
                v.push_back(root->val);
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
        }
        res.push_back(v);
    }
    return res;
}