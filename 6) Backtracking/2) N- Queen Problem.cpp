// https://leetcode.com/problems/n-queens-ii/

class Solution {
public:
    vector<vector<string>>res;
    bool canPlace(vector<string>v,int n,int r,int c)
    {
        
        for(int k=0;k<n;k++)
        {
            if(v[k][c]=='Q') return 0;
        }
        
        for(int i=r,j=c;i<n and j<n;i++,j++)
        {
             if(v[i][j]=='Q') return 0;
        }
        
        for(int i=r,j=c;i>=0 and j>=0;i--,j--)
        {
             if(v[i][j]=='Q') return 0;
        }
        
        for(int i=r,j=c;i>=0 and j<n;i--,j++)
        {
             if(v[i][j]=='Q') return 0;
        }
        
        for(int i=r,j=c;i<n and j>=0;i++,j--)
        {
             if(v[i][j]=='Q') return 0;
        }
        
        return 1;
    }
    void fun(vector<string>v,int n,int i)
    {
        
        if(i==n)
        {
            res.push_back(v);
            return;
        }
        
        for(int j=0;j<n;j++)
        {
            if(canPlace(v,n,i,j))
            {
                v[i][j]='Q';
                fun(v,n,i+1);
                v[i][j]='.';
            }
        }
    }
    int totalNQueens(int n) {
        
        vector<string>v;
        string t(n,'.');
        
        for(int i=0;i<n;i++)
            v.push_back(t);
        
        fun(v,n,0);
        
        return res.size();
    }
};