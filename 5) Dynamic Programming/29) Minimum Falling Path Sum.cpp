// https://leetcode.com/problems/minimum-falling-path-sum/


class Solution {
public:
    
    int dp[102][102];
    int fun(vector<vector<int>>& matrix,int i,int j)
    {
        int r=matrix.size();
        int c=matrix[0].size();
        
        
        if(i>=r) return 0;
        if(j<0 or j>=c) return INT_MAX;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        return dp[i][j]=matrix[i][j]+min({fun(matrix,i+1,j-1),fun(matrix,i+1,j),fun(matrix,i+1,j+1)});
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        memset(dp,-1,sizeof(dp));
        int mi=INT_MAX;
        for(int i=0;i<matrix[0].size();i++)
        {
           mi=min(mi,fun(matrix,0,i));
        }
        
        return mi;
    }
};