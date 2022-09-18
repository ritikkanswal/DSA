// https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    vector<vector<string>>res;
    bool isPalindrome(string& s, int l, int r) 
    {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
    void fun(string s,int i,string k,vector<string>v)
    {
        if(i==s.size())
        {
            res.push_back(v);
            return;
        }
        k="";
        for(int j=i;j<s.size();j++)
        {
            k+=s[j];
            if(isPalindrome(k,0,k.size()-1))
            {
                v.push_back(k);
                fun(s,j+1,k,v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        fun(s,0,"",{});
        return res;
    }
};