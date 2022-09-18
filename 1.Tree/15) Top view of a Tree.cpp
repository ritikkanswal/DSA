// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1#
// Method-1 BFS (vertical level order traversal)

vector<int> topView(Node *root)
{
    vector<int> res;
    map<int, int> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto x = q.front();
        q.pop();
        Node *curr = x.first;
        int i = x.second;
        if (mp.find(i) == mp.end())
            mp[i] = curr->data;
        if (curr->left)
        {
            q.push({curr->left, i - 1});
        }
        if (curr->right)
        {
            q.push({curr->right, i + 1});
        }
    }
    for (auto i : mp)
    {
        res.push_back(i.second);
    }
    return res;
}