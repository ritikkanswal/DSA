// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

class Solution {
public:
    int dp[50001][2];
    int fees;
    int fun(int i, vector<int>& p, int is_empty)
    {
        if(i>=p.size())
        {
            return 0;
        }
        if(dp[i][is_empty]!=-1) return dp[i][is_empty];
        if(is_empty==1)
        {
            return 
                dp[i][is_empty]= 
                max(fun(i+1, p, 0) - p[i], (fun(i+1, p, is_empty)));
        }
        if(is_empty==0)
        {
           return  
               dp[i][is_empty]= 
               max(fun(i+1, p, 1) + p[i]-fees, (fun(i+1, p, is_empty))); 
        }
        return 0;
    }
    int maxProfit(vector<int>& p, int fee) {
        memset(dp, -1, sizeof(dp));
        fees=fee;
        return fun(0, p, 1);
    }
};