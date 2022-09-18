// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1/

class Solution{
    public:
    vector<string>res;
    void fun(vector<vector<int>> &m, int n,int i,int j,map<pair<int,int>,int>&mp,string s)
    {
        if(i<0 or j<0 or i>=n or j>=n or m[i][j]==0) return;
        
        if(mp[{i,j}]) return;
        
        if(i==n-1 and j==n-1)
        {
            res.push_back(s);
        }
        
        mp[{i,j}]=1;
        fun(m,n,i+1,j,mp,s+"D");
        fun(m,n,i,j+1,mp,s+"R");
        fun(m,n,i-1,j,mp,s+"U");
        fun(m,n,i,j-1,mp,s+"L");
        mp[{i,j}]=0;
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        map<pair<int,int>,int>mp;
        
        fun(m,n,0,0,mp,"");
        
        return res;
    }
};
