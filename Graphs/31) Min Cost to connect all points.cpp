class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        
        int sum=0;
        
        vector<pair<int,int>>adj[1002];
        
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                int weight=abs(points[j][0]-points[i][0])+abs(points[j][1]-points[i][1]);
                adj[i].push_back({weight,j});
                adj[j].push_back({weight,i});
            }
        }
        
        map<int,int>vis;
        
        while(!pq.empty())
        {
            auto x=pq.top();
            pq.pop();
            
            int weight=x.first;
            int to=x.second;
            
            if(vis[to])
                continue;
            
            vis[to]=1;
            
            sum+=weight;
            
            for(auto x:adj[to])
            {
                if(vis[x.second]==0)
                    pq.push({x.first,x.second});   
            }
        }
        
        
        return sum;
    }
};

