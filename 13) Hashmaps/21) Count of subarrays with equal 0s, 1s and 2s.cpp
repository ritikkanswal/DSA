
//Method 1(Bruteforce)
// Time Complexity : O(n^2)
// Space Complexity : O(1) 


//Method 2
// Time Complexity : O(n)
// Space Complexity : O(n) 

class Solution {
  public:
    long long getSubstringWithEqual012(string str) {
        
        map<pair<int,int>,int>mp;
        int a=0,b=0,c=0;
        int cnt=0;
        mp[{0,0}]++;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='0') a++;
            else if(str[i]=='1') b++;
            else c++;
            if(mp[{b-a,c-b}])
                cnt+=mp[{b-a,c-b}];
        
            mp[{b-a,c-b}]++;
        }
        return cnt;
    }
};