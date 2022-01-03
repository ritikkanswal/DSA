// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1#
// Method-1 BFS (vertical level order traversal)
vector<int> topView(Node *root)
{
    Node *curr;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    vector<int> ans;
    map<int, vector<int>> mymap;

    //BFS
    while (!q.empty())
    {
        int size = q.size();
        map<int, set<int>> mapset;

        for (int i = 0; i < size; i++)
        {
            curr = q.front().first;
            int col = q.front().second;
            q.pop();
            mapset[col].insert(curr->data);

            if (curr->left)
                q.push({curr->left, col - 1});
            if (curr->right)
                q.push({curr->right, col + 1});
        }
        for (auto it : mapset)
            for (auto it2 : it.second)
                mymap[it.first].push_back(it2);
    }
    //Now pass all values from mymap to ans array
    for (auto it : mymap)
        ans.push_back(it.second[0]);

    return ans;
}