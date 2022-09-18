#include <bits/stdc++.h>
using namespace std;

class DSU
{

    int *parent;
    int *rank;

public:
    DSU(int n)
    {
        parent = new int[n];
        rank =new int[n];

        // parent=-1,rank=1

        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    // find function

    int find(int i)
    {

        // base cases
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }

    // unite (union)

    void unite(int x, int y)
    {

        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graph
{
    int V;
    vector<vector<int>> l;

public:
    Graph(int v)
    {
        V = v;
    }

    void addEdge(int i, int j, int w, bool undir = true)
    {
        l.push_back({w, i, j});
    }

    int kruskal_mst()
    {

        sort(l.begin(), l.end());


        DSU s(V);
        int ans = 0;

        for (auto edge : l)
        {

            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            if (s.find(x) != s.find(y))
            {
                s.unite(x, y);
                ans += w;
            }
        }

        return ans;
    }
};
int main()
{
    int V = 10;
    Graph g(V);

    // g.addEdge(0, 1, 4);
    // g.addEdge(0, 7, 8);
    // g.addEdge(1, 2, 8);
    // g.addEdge(1, 7, 11);
    // g.addEdge(2, 3, 7);
    // g.addEdge(2, 8, 2);
    // g.addEdge(2, 5, 4);
    // g.addEdge(3, 4, 9);
    // g.addEdge(3, 5, 14);
    // g.addEdge(4, 5, 10);
    // g.addEdge(5, 6, 2);
    // g.addEdge(6, 7, 1);
    // g.addEdge(6, 8, 6);
    // g.addEdge(7, 8, 7);
    

    g.addEdge(3, 6, 1);
    g.addEdge(3, 5, 3);
    g.addEdge(5, 6, 3);
    g.addEdge(7, 9, 2);
    g.addEdge(6, 8, 6);
    g.addEdge(5, 4, 7);
    g.addEdge(2, 4, 8);
    g.addEdge(4, 7, 8);
    g.addEdge(2, 3, 9);
    g.addEdge(7, 8, 9);
    g.addEdge(1, 2, 10);
    g.addEdge(4, 6, 10);
    g.addEdge(8, 9, 11);
    g.addEdge(1, 3, 12);

    cout << g.kruskal_mst() << endl;
    return 0;
}