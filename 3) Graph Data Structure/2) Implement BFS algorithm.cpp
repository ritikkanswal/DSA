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
    void bfs(int node)
    {
        bool visited[v]={false};
        queue<int>q;
        q.push(node);

        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            visited[curr]=true;
            cout<<curr<<" ";
            for(auto x:l[curr])
            {
               
                if(!visited[x])
                q.push(x);
            }
        }
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
    g.bfs(1);
    return 0;
}