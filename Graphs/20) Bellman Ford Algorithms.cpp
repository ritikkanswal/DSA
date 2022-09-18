#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>> l;

public:
    Graph(int v)
    {
        V = v;
    }

    void addEdge(int i, int j, int w, bool undir = false)
    {
        l.push_back({i, j, w});
    }

    int shortest_path(int S)
    {
        vector<int> dis(V + 1, INT_MAX);
        dis[S] = 0;
        int res = 0;

        for (int i = 0; i < V - 1; i++)
        {
            for (int j = 0; j < l.size(); j++)
            {
                int u = l[j][0];
                int v = l[j][1];
                int wt = l[j][2];

                if (dis[u] != INT_MAX and dis[u] + wt < dis[v])
                    dis[v] = dis[u] + wt;
            }
        }

        for (int i = 1; i <= V; i++)
        {
            res = max(res, dis[i]);
        }

        if (res == INT_MAX)
            return -1;

        return res;
    }
};

int main(int argc, char **argv)
{
    Graph g(4);

    g.addEdge(2, 1, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);

    cout << g.shortest_path(2) << endl;
}