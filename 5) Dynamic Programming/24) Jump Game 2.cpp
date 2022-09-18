// https://leetcode.com/problems/jump-game-ii/


class Solution {
public:
    int dp[10001];
    int res = INT_MAX;
    
    int fun(vector<int>& nums, int j)
    {
        if(j>=nums.size()-1)
        {
            return 0;
        }
        
        if(nums[j]==0)
            return 1e6;
        
        if(dp[j]<1e6)
            return dp[j];
        
        
        for(int i = j+1; i<=j+nums[j]; i++)
        {
            dp[j] = min(dp[j], fun(nums, i));
        }
        
        dp[j]+=1;
        return dp[j];
        
    }
    
    int jump(vector<int>& nums) {
        memset(dp, 1e6, sizeof dp);
        return fun(nums, 0);
    }
};