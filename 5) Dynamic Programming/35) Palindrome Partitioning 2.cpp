// https://leetcode.com/problems/palindrome-partitioning-ii/


class Solution {
public:
    vector<vector<string>>res;
    int dp[2002][2002];
    bool isPalindrome(string& s, int l, int r) 
    {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
    int fun(string &s,int i,int j)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i>=j or isPalindrome(s,i,j))
            return 0;
        int mi=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int left=0,right=0;
            
            left=isPalindrome(s,i,k);
            if(!left) continue;
            
            right=fun(s,k+1,j);
            int count=1+right;
            mi=min(mi,count);
        }
        return dp[i][j]=mi;
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        return fun(s,0,s.size()-1);
    }
};