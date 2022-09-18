// https://leetcode.com/problems/palindrome-partitioning-iv/

class Solution {
public:
    int dp2[2001][2001];
    int ans = 0;
    
    int palindrome(string &s, int i, int j)
    {
      if(s.size()==2)
       {
           if(s[0]==s[1]) dp2[i][j]=1;
           else dp2[i][j]=0;
       }
        int x=s[0];
        int y=s[s.size()-1];
        
        if(x==y && dp2[i+1][j-1]) dp2[i][j]=1;
        else dp2[i][j]=0;
        
        return dp2[i][j];
    }
    
    void countSubstrings(string &s) {
       memset(dp2,-1,sizeof(dp2)); 
       string temp;
       for(int i=s.size()-1;i>=0;i--)
       {
           temp=s[i];
           dp2[i][i]=1;
           for(int j=i+1;j<s.size();j++)
           {
               temp+=s[j];
               palindrome(temp, i, j);
           }
       }
    }
   
    bool solve(string &s,int i,int j,int k)
    {
        string t;
        if(k==0)
            return dp2[i][j];
        for(int l=i;l<s.size()-1;l++)
        {
            if(dp2[i][l] and solve(s,l+1,j,k-1))
                return true;
        }
        return false;
    }
    bool checkPartitioning(string s) {
        countSubstrings(s);
        return solve(s,0,s.size()-1,2);
    }
};