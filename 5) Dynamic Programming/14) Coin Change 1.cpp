// https://leetcode.com/problems/coin-change/


// Method 1 (Recursion+Memoisation) (top down)
// Time Complexity : O(n)
// Space Complexity : O(n)



class Solution {
public:
    int dp[10001][13];
    int fun(vector<int>& coins, int amount,int i)
    {
        if(amount==0) return 0; 
        
        if(amount<0) return INT_MAX-1;
        if(i<0 or i>=coins.size()) return INT_MAX-1;
        
        if(dp[amount][i]!=-1) return dp[amount][i];
        
        // it is extra it can be achieved by val2 in another recursive call
        int val1=1+fun(coins,amount-coins[i],i+1);
        int val2=fun(coins,amount,i+1);
        int val3=1+fun(coins,amount-coins[i],i);
        
        return dp[amount][i] = min({val1,val2,val3});
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof dp);
        int val=fun(coins,amount,0);
        
        if(val==INT_MAX-1) return -1;
        return val;
    }
};