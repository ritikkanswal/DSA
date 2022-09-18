//https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Method - 1
// Bruteforce
// Time -> O(n3)


// Method - 2
// Time -> O(n)
// Space -> O(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        if(s.size()==1) return 1;
        map<int,int>mp;
        
        int i=-1,j=0;
        
        int ma=-1;
        
        while(j<s.size())
        {   
            // "abba" ->when a encounter again it will change i to next of a
            // that is wrong
            if(mp[s[j]]!=0 and mp[s[j]]-1>i)
                i=mp[s[j]]-1;
            
            ma=max(ma,(j-i));
            mp[s[j]]=j+1;
            
            j++;
        }
        return ma;
    }
};