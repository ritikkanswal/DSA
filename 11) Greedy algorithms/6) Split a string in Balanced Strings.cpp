// https://leetcode.com/problems/split-a-string-in-balanced-strings/


class Solution {
public:
    int balancedStringSplit(string s) {
        int r=0,cnt=0;
        for(auto x:s)
        {
            if(x=='R') r++;
            else r--;
            if(r==0) cnt++;
        }
        return cnt;
    }
};