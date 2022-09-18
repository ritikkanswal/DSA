#include<bits/stdc++.h>
using namespace std;
class Graph{
    int v;
    list<int>*l;
    public:
    Graph(int v)
    {
       this->v=v;
       l=new list<int>[v];
    }
    void addEdge(int i,int j,bool undir=true)
    {
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }
    void dfs_helper(int node,bool visited[])
    {
        if(visited[node]) return;
        cout<<node<<" ";
        visited[node]=true;
        for(auto x:l[node])
            dfs_helper(x,visited);
    }
    void dfs(int node)
    {
        bool visited[v]={false};
        cout<<"DFS of this Graph is : ";
        dfs_helper(node,visited);
    }
};
int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 5);
    g.addEdge(0, 4);
    g.addEdge(3, 4);
    g.dfs(1);
    return 0;
}