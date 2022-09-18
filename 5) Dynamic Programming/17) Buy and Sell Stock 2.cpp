// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i-1]<prices[i])
                sum+=prices[i]-prices[i-1];
        }
        return sum;
    }
};




class Solution {
public:
    int dp[30001][2];
    int solve(vector<int>& prices, int i, int isempty)
    {
        if(i>=prices.size())
            return 0;
        
        if(dp[i][isempty]!=-1)
            return dp[i][isempty];
    
    if(isempty == 1)
    {
        return dp[i][isempty] = 
            max(solve(prices, i+1, isempty), (solve(prices, i+1, !isempty))-prices[i]);
    }
    
    if(isempty == 0)
    {
        return dp[i][isempty] = 
            max(solve(prices, i+1, isempty), (solve(prices, i+1, !isempty))+prices[i]);
    }
    
    return 0; 
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        int isempty = 1;
        return solve(prices, 0, isempty);
    }
};


