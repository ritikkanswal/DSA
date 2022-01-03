// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
void dfs(Node *root,int level,vector<int>&res)
{
    if(!root) return;
    if(level>=res.size())
    res.push_back(root->data);
    dfs(root->left,level+1,res);
    dfs(root->right,level+1,res);
}
vector<int> leftView(Node *root)
{
   vector<int>res;
   dfs(root,0,res);
   return res;
}

