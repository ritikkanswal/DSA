// https://leetcode.com/problems/combination-sum/



class Solution {
public:
    vector<vector<int>>res;
    map<vector<int>,int>mp;
    void helper(vector<int>& candidates, int target,vector<int>v,int sum,int i)
    {
        if(sum>target) return;
        if(sum==target)
        {
            if(!mp[v])
            res.push_back(v);
            mp[v]++;
            return;
        }
        if(i==candidates.size())
            return;
        for(int j=i;j<candidates.size();j++)
        {
            v.push_back(candidates[j]);
            helper(candidates,target,v,sum+candidates[j],j);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        helper(candidates,target,{},0,0);
        return res;
    }
};