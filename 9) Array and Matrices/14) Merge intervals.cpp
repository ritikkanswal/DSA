// https://leetcode.com/problems/merge-intervals/

vector<vector<int>> merge(vector<vector<int>> &in)
{
    sort(in.begin(), in.end());
    vector<vector<int>> res;
    int n = in.size();
    int mi = in[0][0], ma = in[0][1];
    for (int i = 1; i < n; i++)
    {
        if (in[i][0] <= ma)
        {
            ma = max(ma, in[i][1]);
        }
        else
        {
            res.push_back({mi, ma});
            mi = in[i][0];
            ma = in[i][1];
        }
    }
    res.push_back({mi, ma});
    return res;
}