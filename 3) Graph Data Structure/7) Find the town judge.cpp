int findJudge(int n, vector<vector<int>> &trust)
{
    map<int, int> outbound;
    map<int, int> inbound;
    for (auto x : trust)
    {
        outbound[x[0]]++;
        inbound[x[1]]++;
    }

    for (int x = 1; x <= n; x++)
    {
        if (inbound[x] == n - 1 and outbound[x] == 0)
            return x;
    }

    return -1;
}