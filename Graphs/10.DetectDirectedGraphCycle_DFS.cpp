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
    bool dfsHelper(int node,vector<bool>&visited,vector<bool>&stack)
    {
        visited[node]=true;
        stack[node]=true;
        for(int nbr:l[node])
        {
            if(stack[nbr])
                return 1;
            else if(!visited[nbr]){
                bool nbrFoundAcycle=dfsHelper(nbr,visited,stack);
                if(nbrFoundAcycle)
                    return 1;
            }
        }
        stack[node]=false;
        return 0;
    }
    bool contains_cycle()
    {
       vector<bool>visited(V,0);
       vector<bool>stack(V,0);
       for(int i=0;i<V;i++)
       {
           if(!visited[i])
           if(dfsHelper(i,visited,stack))
                return 1;
       }
       return 0;
    }
};
int main()
{
    Graph g(3);
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    // g.addEdge(2,0);
    if(g.contains_cycle())
        cout<<"Cycle Detected!!\n";
    else
        cout<<"Cycle Not Detected!!\n";
    return 0;
}