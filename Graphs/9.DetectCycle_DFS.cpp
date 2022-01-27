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

    void addEdge(int i,int j,bool undir=true)
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
    bool dfsHelper(int node,bool *visited,int parent)
    {
        visited[node]=true;
        for(int nbr:l[node])
        {
            if(!visited[nbr]){
                bool nbrFoundAcycle=dfsHelper(nbr,visited,node);
                if(nbrFoundAcycle)
                    return 1;
            }
            else if(nbr!=parent) return 1;
        }
        return 0;
    }
    bool contains_cycle()
    {
    bool *visited=new bool[V]{0};
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        if(dfsHelper(i,visited,-1))
        return 1;
    }
    return 0;
    }
};
int main()
{
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.addEdge(0,4);
    g.addEdge(3,4);
    if(g.contains_cycle())
    cout<<"Cycle Detected!!"<<endl;
    else
    cout<<"Cycle Not Detected!!"<<endl;
    return 0;
}