/// https://leetcode.com/problems/rabbits-in-forest/


//Time Complexity : O(n)
//Space Complexity : O(1)

class Solution {
public:
    int numRabbits(vector<int>& a) {
        map<int, int>m;
        int cnt=0;
        for(int i=0;i<a.size();i++)
        {
            //if we found new color rabbit add it
            if(m[a[i]]==0) cnt+=a[i]+1;
            m[a[i]]++;
            
            //if we have taken opinion of all rabbit of same color
            //then ,this time onwards we will consider them as a different color rabbit
            if(m[a[i]]==a[i]+1) m[a[i]]=0;
        }
        return cnt;
    }
};