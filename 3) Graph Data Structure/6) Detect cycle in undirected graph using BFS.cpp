

// Time Complexity: O(N+E),  N is the time taken and E is for traveling through adjacent nodes overall. 
// Space Complexity: O(N+E) +  O(N) + O(N) , space for adjacent list , array and queue

class Graph
{
public:
    int v;
    list<int> *l;

public:
    Graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }
    void addEdge(int i, int j, bool undir = true)
    {
        l[i].push_back(j);
    }
    bool checkForCycle(int s, vector<int> &visited)
    {
        queue<pair<int, int>> q;
        visited[s] = true;
        q.push({s, -1});

        while (!q.empty())
        {
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
            for (auto it : l[node])
            {
                if (!visited[it])
                {
                    visited[it] = true;
                    q.push({it, node});
                }
                else if (par != it)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool contains_cycle()
    {
        vector<int> vis(v, 0);
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                if (checkForCycle(i, vis))
                {

                    return true;
                }
            }
        }
        return 0;
    }
};
int main()
{
    Graph g(5);
    g.addEdge(1, 4);
    g.addEdge(1, 0);
    // g.addEdge(3, 5);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(0, 2);
    // g.addEdge(3, 4);
    cout << g.isCycle();
    return 0;
}