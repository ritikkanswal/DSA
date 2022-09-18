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
    bool dfs_helper(int node,bool visited[],int parent)
    {
        if(visited[node]) return 0;
        visited[node]=true;
        for(auto x:l[node])
        {
            if(!visited[x])
            {
                bool ch=dfs_helper(x,visited,node);
                if(ch)
                return 1;
            }
            else{
                if(x!=parent) return 1;
            }
        }
        return 0;
    }
    bool dfs()
    {
        bool visited[v]={false};
        for(int i=0;i<v;i++)
        if(dfs_helper(i,visited,-1)) return 1;

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
    cout<<g.dfs();
    return 0;
}