// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1/


class Solution {
{
	public:
	vector<string>res;
	
	void fun(string s,int i)
	{
	    if(i==s.size()-1)
	    {
	        res.push_back(s);
	        return;
	    }
	    
	    
	    for(int j=i;j<s.size();j++)
	    {
	        swap(s[i],s[j]);
	        fun(s,i+1);
	    }
	}
	
	vector<string>find_permutation(string S)
	{
	    sort(S.begin(),S.end());
	    fun(S,0);
	    return res;
	}
};