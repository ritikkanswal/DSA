#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<pair<int, int>> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<pair<int, int>>[v];
    }

    void addEdge(int i, int j, int w, bool undir = true)
    {
        l[i].push_back({j, w});
        if (undir)
        {
            l[j].push_back({i, w});
        }
    }
    int prim_mst()
    {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

        vector<bool> vis(V, 0);
        int ans = 0;

        Q.push({0, 0});

        while (!Q.empty())
        {

            auto best = Q.top();
            Q.pop();

            int to = best.second;
            int weight = best.first;

            if (vis[to])
            {
                continue;
            }

            ans += weight;
            vis[to] = 1;

            for (auto x : l[to])
            {
                if (vis[x.first] == 0)
                {
                    Q.push({x.second, x.first});
                }
            }
        }
        return ans;
    }
};
int main()
{
    int V = 9;
    Graph g(V);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    cout << g.prim_mst() << endl;
    return 0;
}