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
    void addEdge(int i,int j,bool undir=false)
    {
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }
    bool dfs_helper(int node,bool visited[],vector<int>&stack)
    {

        visited[node] = true;
        stack[node]=1;

        for(auto x:l[node]){
            if(!visited[x])
            {
                bool ch=dfs_helper(x,visited,stack);
                if(ch) return 1;
            }
            else
            {
                if(stack[node]) return 1;
            }
        }
        stack[node]=0;
        return 0;
    }
    bool dfs()
    {
        bool visited[v]={false};
        
        for(int i=0;i<v;i++)
        {
            vector<int>stack(v,0);
            if(dfs_helper(i,visited,stack)) return 1;
        }
        

        return 0;
    }
};
int main()
{
    Graph g(7);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(0, 5);
    g.addEdge(5, 4);
    cout<<g.dfs();
    return 0;
}