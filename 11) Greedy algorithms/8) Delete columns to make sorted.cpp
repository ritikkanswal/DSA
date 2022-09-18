// https://leetcode.com/problems/delete-columns-to-make-sorted/


class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cnt=0;
        for(int i=0;i<strs[0].size();i++)
        {
            char x='a';
            for(int j=0;j<strs.size();j++)
            {
                if(strs[j][i]<x)
                {
                    cnt++;
                    break;
                }
                x=strs[j][i];
            }
        }
        return cnt;
    }
};