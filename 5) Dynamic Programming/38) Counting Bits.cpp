// https://leetcode.com/problems/counting-bits/

//Method-1 
//Bruteforce


//Method-2 
// use previous data instead of calculationg new data
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>v(num+1,0);
        for(int i=0;i<=num;i++){
            v[i]=v[i/2]; if(i&1) v[i]+=1;}
        return v;
    }
};