// https://leetcode.com/problems/partition-equal-subset-sum/

// Method 1 (Recursion+Memoisation) (top down)
// Time Complexity : O(n)
// Space Complexity : O(n)


class Solution {
public:
    int dp[20002][202];
    bool solve(vector<int>&arr, int sum,int i)
    {
        if(sum==0) return 1;
        
        if(i>=arr.size() or sum<0)
            return 0;
        
        if(dp[sum][i]!=-1) return dp[sum][i];
        
        return dp[sum][i]=solve(arr,sum-arr[i],i+1) or solve(arr,sum,i+1);
    }
    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int total_sum=0;
        for(auto x:nums)
            total_sum+=x;
        if(total_sum%2==1) return 0;
        return solve(nums,total_sum/2,0);
    }
};