#include<bits/stdc++.h>
using namespace std;
class Graph{

    //Adjacency List
    vector<pair<int,int>>*l;
    int V;
    public:
    Graph(int n){
        V=n;
        l=new vector<pair<int,int>>[n];
    }

    void addEdge(int x,int y,int w){
        l[x].push_back({y,w});
        l[y].push_back({x,w});
    }

    int prim(){

        //most important stuff is
        //Init a Min Heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int >>>Q;

        //another array
        //visited array that denotes whether a node has included or note
        bool *visited=new bool[V]{0};
        int ans=0;

        //begin
        Q.push({0,0}); //weight,nodes

        while(!Q.empty()){
            auto best=Q.top();
            Q.pop();

            int to=best.second;
            int weight=best.first;

            if(visited[to]){
                //discard the edge , and continue;
                continue;
            }
            
            //otherwise take the current edge
            ans+=weight;
            visited[to]=1;

            //add the new edges in the queue
            for(auto x:l[to]){
                if(visited[x.first]==0){
                    Q.push({x.second,x.first});
                }
            }
        }
        return ans;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        g.addEdge(x-1,y-1,w);
    }
    cout<<g.prim()<<endl;
}