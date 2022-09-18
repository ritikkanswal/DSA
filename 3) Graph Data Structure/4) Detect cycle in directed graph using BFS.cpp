//Method-1(using Kahn's Algorithm)
//Kahn's algo only work on DAG graph nodes
//Kahn's algo does not work on cyclic Graph

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
        bool findTopoSort() 
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
    	    
    	    return res.size()!=v;
    	}
    };