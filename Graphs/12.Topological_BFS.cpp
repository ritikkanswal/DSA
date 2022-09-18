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
    void topological_sort()
    {
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto nbr:l[i])
            {
                indegree[nbr]++;
            }
                
        }

        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int curr=q.front();
            cout<<curr<<",";
            q.pop();
            for(auto nbr:l[curr])
            {
                indegree[nbr]--;
                if(indegree[nbr]==0)
                q.push(nbr);
            }
        }

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
    g.topological_sort();
    return 0;
}