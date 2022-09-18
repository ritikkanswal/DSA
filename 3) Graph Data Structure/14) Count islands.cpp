class Solution {
public:
    bool vis[302][302];
    void dfs(vector<vector<char>>& nums,int i,int j)
    {
        if(i<0 or j<0 or i>=nums.size() or j>=nums[0].size() or vis[i][j] or nums[i][j]=='0') return;
        vis[i][j]=1;
        
        dfs(nums,i+1,j);
        dfs(nums,i,j+1);
        dfs(nums,i-1,j);
        dfs(nums,i,j-1);
    }
    int numIslands(vector<vector<char>>& nums) {
        int cnt=0;
        
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums[0].size();j++)
            {
                if(!vis[i][j] and nums[i][j]=='1')
                {
                   dfs(nums,i,j);
                   cnt++;
                }
            }
        }
        return cnt;
    }
};