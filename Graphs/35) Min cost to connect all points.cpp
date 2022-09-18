class Solution {
public:
    int parent[1001];
    long long rank[1001];
    bool Union(int i,int j)
    {
        int x=Find(i);
        int y=Find(j);
        
        if(x!=y)
        {
            if(rank[x]>rank[y])
                parent[y]=x,rank[x]+=rank[y];
            else
                parent[x]=y,rank[y]+=rank[x];  
        } 
        else
            return  1;
        
        return 0;
    }
    int Find(int i)
    {
        if(parent[i]==-1)
            return i;
        return Find(parent[i]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        memset(parent,-1,sizeof(parent));
        for(int i=0;i<1001;i++) rank[i]  = 1;
        
        int sum=0;
        
        vector<vector<int>>adj;
        
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                int weight=abs(points[j][0]-points[i][0])+abs(points[j][1]-points[i][1]);
                adj.push_back({weight,i,j});
            }
        }
        
        sort(adj.begin(),adj.end());
        int cnt=0;
        for(auto x:adj)
        {
            
            int i=x[1];
            int j=x[2];
            int weight=x[0];
            
            if(Find(i)!=Find(j))
                sum+=weight,Union(i,j),cnt++;
            
            if(cnt==adj.size()-1) return sum;
            
            
        }
        
        return sum;
    }
};