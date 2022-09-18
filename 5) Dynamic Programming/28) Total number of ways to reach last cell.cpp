// https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int dp[102][102];
    int fun(int x,int y,int m,int n)
    {
        if(x==m-1 and y==n-1) return 1;
        if(x==m||y==n) return 0;
        if(dp[x][y]!=-1)
            return dp[x][y];
        return dp[x][y]=fun(x+1,y,m,n)+fun(x,y+1,m,n);
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return fun(0,0,m,n);
    }
};