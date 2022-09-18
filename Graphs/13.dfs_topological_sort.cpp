#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int>*l;
    public:
    Graph(int v)
    {
        V=v;
        l=new list<int>[v];
    }

    void addEdge(int i,int j,bool undir=false)
    {
        l[i].push_back(j);
        if(undir)
        {
            l[j].push_back(i);
        }
    }
    void printAdjList(){
        for(int i=0;i<V;i++)
        {
            cout<<i<<"--->";
            for(auto node:l[i])
            {
                cout<<node<<",";
            }
            cout<<endl;
        }
    }
    void dfs(int node,vector<bool>&visited,list<int>&ordering){
        visited[node]=true;
        for(auto nbr:l[node]){
            if(!visited[nbr]){
                dfs(nbr,visited,ordering);
            }
        }
        ordering.push_front(node);
    }
    void dfs_topological_sort()
    {
        vector<bool>visited(V,false);
        list<int>ordering;

        for(int i=0;i<V;i++){
            if(!visited[i])
                dfs(i,visited,ordering);
        }

        for(auto node:ordering){
            cout<<node<<" ";
        }
        cout<<endl;

    }
};
int main()
{
    Graph g(6);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.dfs_topological_sort();
    return 0;
}