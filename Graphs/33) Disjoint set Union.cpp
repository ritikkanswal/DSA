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

    void addEdge(int i, int j)
    {
        l.push_back({i, j});
    }

    // find function

    int find(int i, int parent[])
    {

        // base cases
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i], parent);
    }

    // unite (union)

    void unite(int x, int y, int parent[], int rank[])
    {

        int s1 = find(x, parent);
        int s2 = find(y, parent);

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

    bool contains_cycle()
    {
        int *parent = new int[V];
        int *rank = new int[V];

        for (int i = 0; i < V; i++)
            parent[i] = -1, rank[i] = 1;

        for (auto edge : l)
        {
            int i = edge[0];
            int j = edge[1];

            int s1 = find(i, parent);
            int s2 = find(j, parent);

            if (s1 != s2)
                unite(s1, s2, parent, rank);

            else
            {
                cout << "Same parents" << s1 << " and " << s2 << endl;
                return 1;
            }
        }
    }
};

int main(int argc, char **argv){
    Graph g(4);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);

    cout<<g.contains_cycle() << endl;
}