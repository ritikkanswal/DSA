// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1#

//Method 1 (BFS)
vector<int> bottomView(Node *root)
{
    Node *curr;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    vector<int> ans;
    map<int, int> mymap;

    //BFS
    while (!q.empty())
    {
        int size = q.size();
        map<int, int> mapset;

        for (int i = 0; i < size; i++)
        {
            curr = q.front().first;
            int col = q.front().second;
            q.pop();
            mapset[col] = curr->data;

            if (curr->left)
                q.push({curr->left, col - 1});
            if (curr->right)
                q.push({curr->right, col + 1});
        }
        for (auto it : mapset)
            mymap[it.first] = (it.second);
    }
    //Now pass all values from mymap to ans array
    for (auto it : mymap)
        ans.push_back(it.second);

    return ans;
}

