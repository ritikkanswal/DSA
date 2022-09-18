//Method - 1

class Solution {
public:
    class Graph
    {
        int V;
        list<pair<int, int>> *l;

    public:
        Graph(int v)
        {

            V = v;
            l = new list<pair<int, int>>[V];
        }

        void addEdge(int i, int j, int w, bool undir = false)
        {
            l[i].push_back({j, w});
            if (undir)
            {
                l[j].push_back({i, w});
            }
        }
        int shortestPath(int src)
        {
           vector<int>dist(V,INT_MAX);
           dist[src]=0;
           set<pair<int,int>>s;
           s.insert({0,src});
           while(!s.empty()){
               auto it=s.begin();
               int node=it->second;
               int distTillNow=it->first;
               s.erase(it);

               for(auto nbrPair:l[node]){

                   int nbr=nbrPair.first;
                   int currentEdge=nbrPair.second;

                   if((distTillNow+currentEdge)<dist[nbr]){
                    auto f=s.find({dist[nbr],nbr});
                       if(f!=s.end()){
                           s.erase(f);
                       }
                    dist[nbr]=(distTillNow+currentEdge);
                    s.insert({(distTillNow+currentEdge),nbr});
                   }
               }
           }
           
           int ma=0;
           for(int i=1;i<V;i++)
           {
               ma=max(dist[i],ma);
           }
            
           return ma;
        }
    };
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        Graph g(n+1);
        
        for(auto x:times)
        {
            g.addEdge(x[0],x[1],x[2]);
        }
       
        int val=g.shortestPath(k);
        
        if(val==INT_MAX) return -1;
        
        return val;
    }
};

//Method -2


class Solution {
public:
    int shortestPath(vector<vector<int>>&edges,int n,int sc)
    {
        vector<int>dis(n+1,INT_MAX);
        dis[sc]=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<edges.size();j++)
            {
                int u=edges[j][0];
                int v=edges[j][1];
                int w=edges[j][2];
                
                if(dis[u]!=INT_MAX and (dis[u]+w)<dis[v])
                {
                    dis[v]=dis[u]+w;
                }
            }
        }
        int ma=0;
        for(int i=1;i<=n;i++)
        {
            if(dis[i]==INT_MAX) return -1;
            ma=max(ma,dis[i]);
        }
        return ma;
       
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) { 
        return shortestPath(times,n,k);
    }
};