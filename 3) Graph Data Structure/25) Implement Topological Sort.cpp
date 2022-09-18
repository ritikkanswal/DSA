//Method 1(using DFS)
// Time Complexity: O(N+E) 
// N = Number of node , E = Number of Edges
// Space Complexity: O(N) + O(N)
// Visited Array and Stack data structure. Both will be using O(N).
// Auxiliary Space Complexity:  O(N)
// Recursion call of DFS

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
    void helper(int src,vector<int>&vis,stack<int>&st)
    {
        vis[src]=1;
        
        for(auto nbr:l[src])
        {
            if(!vis[nbr])
            {
                helper(nbr,vis,st);
            }
        }
        st.push(src);
    }
    vector<int> findTopoSort()
    {
        vector<int>vis(v,0),res;
        stack<int>st;
        
        for(int i=0;i<v;i++)
        {
            if(!vis[i])
            {
                helper(i,vis,st);
            }
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};
int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    
    auto v=g.findTopoSort();
    
    for(auto x:v){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}




//Method 2(using BFS)(Kahn Algorithm)
// Time Complexity: O(N+E)

// Space complexity: O(N)+O(N)
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
    vector<int> findTopoSort() 
	{
	    
	    vector<int>res;
	    
	    vector<int>indegree(v,0);
	    queue<int>q;
	    for(int i=0;i<v;i++)
	    {
	        for(auto x:l[i])
	        {
	            indegree[x]++;
	        }
	    }
	    
	    for(int i=0;i<v;i++)
	    {
	        if(indegree[i]==0)
	        q.push(i);
	    }
	    
	    while(!q.empty())
	    {
	        int curr=q.front();
	        q.pop();
	        res.push_back(curr);
	        for(auto x:l[curr])
	        {
	            indegree[x]--;
	            
	            if(indegree[x]==0) q.push(x);
	        }
	    }
	    
	    return res;
	}
};
int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    
    auto v=g.findTopoSort();
    
    for(auto x:v){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}

