// https://leetcode.com/problems/decode-ways/



class Solution {
public:
    int dp[1001];
    int solve(string s,int i)
    {
        if(dp[i]!=-1) return dp[i];
        
        if(s.size()==i) return 1;
        
        if(s[i]=='0') return 0;
        
        if(s.size()-i==1) return 1;
        
        int way1=solve(s,i+1);
        int way2=0;
        int value=stoi(s.substr(i,2));
        if(value<=26)
            way2=solve(s,i+2);
        dp[i]=way1+way2;
        return dp[i];
            
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0);
    }
};