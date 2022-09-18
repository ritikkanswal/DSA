#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<pair<int,int>>*l;
    public:
    Graph(int v)
    {
        V=v;
    }

    void addEdge(int i,int j,int w,bool undir=true)
    {
        l[i].push_back({j,w});
        if(undir)
        {
            l[j].push_back({i,w});
        }
    }
    int shortestPath(int src,int dest){
        vector<int>dist(V,INT_MAX);
        set<pair<int,int>>s;

        dist[src]=0;
        s.insert({0,src});

        while(!s.empty())
        {
            auto it=s.begin();
            int node=it->second;
            int distTillNow=it->first;        
            s.erase(it);

            for(auto nbrPair:l[node]){

                int nbr=nbrPair.second;
                int currentEdge=nbrPair.first;

                if((distTillNow+currentEdge)<dist[nbr]){

                    auto f=s.find({dist[nbr],nbr});
                    if(f!=s.end()){
                        s.erase(f);
                    }

                    dist[nbr]=distTillNow+currentEdge;
                    s.insert({dist[nbr],nbr});
                }
            }
        }

        for(int i=0;i<V;i++){
            cout<<"Node "<<i<<" Dist "<<dist[i]<<endl;
        }
        return dist[dest];
    }
};
int main()
{
    Graph g(5);
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(0,2,4);
    g.addEdge(0,3,7);
    g.addEdge(3,2,2);
    g.addEdge(3,4,3);
    cout<<g.shortestPath(0,4);
    return 0;
}