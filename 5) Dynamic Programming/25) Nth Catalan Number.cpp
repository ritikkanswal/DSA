// https://leetcode.com/problems/unique-binary-search-trees/

class Solution {
public:
    int dp[20];
    int numTrees(int n) {
        
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=n;i++)
        {
            int sum=0;
            for(int j=0;j<i;j++)
            {
                sum+=dp[j]*dp[i-j-1];
            }
            dp[i]=sum;
        }
        
        return dp[n];
    }
};
