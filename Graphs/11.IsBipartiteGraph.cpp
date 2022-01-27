#include<bits/stdc++.h>
using namespace std;
int main()
{
    int v,e,u,v;
    cin>>v>>e;
    vector<int>adj[v];
    for(int i=0;i<e;i++) {
        cin>>u>>v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    dfs_helper()
    return 0;
}