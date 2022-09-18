





//METHOD 1 (BFS)

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
   
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    int i=KnightPos[0]-1;
	    int j=KnightPos[1]-1;
	    
	    int x=TargetPos[0]-1;
	    int y=TargetPos[1]-1;
	    
	    queue<vector<int>>q;
	    q.push({i,j,0});
	    
	    int cnt=0;
	    
	    int vis[1001][1001]={false};
	    int mi=INT_MAX;
	    while(!q.empty())
	    {
	        cnt++;
	        vector<int>curr=q.front();
	        q.pop();
	        
	        int a=curr[0];
	        int b=curr[1];
	        int k=curr[2];
	        
	        if(a<0 or b<0 or a>=n or b>=n) continue;
	        
	        if(vis[a][b]) continue;
	        
	        vis[a][b]=1;
	        
	        
	        if(a==x and b==y)
	        {
	           return k;
	        }
	        
	        q.push({a+2,b-1,k+1});
	        q.push({a+2,b+1,k+1});
	        q.push({a-2,b-1,k+1});
	        q.push({a-2,b+1,k+1});
	        q.push({a+1,b-2,k+1});
	        q.push({a+1,b+2,k+1});
	        q.push({a-1,b-2,k+1});
	        q.push({a-1,b+2,k+1});
	    }
	    
	    return mi;
	}
};