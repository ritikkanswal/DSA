// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/#

// Method 1 (Recursion+Memoisation) (top down)
// Time Complexity : O(n*sum)
// Space Complexity : O(n*sum)


class Solution{   
public:
    int dp[10005][101];
    bool solve(vector<int>&arr, int sum,int i)
    {
        if(sum==0) return 1;
        
        if(i>=arr.size() or sum<0)
        {
            return 0;
        }
        
        if(dp[sum][i]!=-1) return dp[sum][i];
        
        return dp[sum][i]=solve(arr,sum-arr[i],i+1) or solve(arr,sum,i+1);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        memset(dp,-1,sizeof(dp));
        return solve(arr,sum,0);
    }
};