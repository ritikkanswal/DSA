#include<bits/stdc++.h>
using namespace std;
int atMost(string &nums, int k)
{
    map<int,int>mp;
    
    int i=0,j=0;
    
    int cnt=0;
    
    while(j<nums.size())
    {
        mp[nums[j]]++;
        
        if(mp.size()>k)
        {
            while(mp.size()>k)
            {
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                    mp.erase(nums[i]);
                i++;
            }
        }
        int n=j-i+1;
        cnt+=n;
        j++;
    }
    return cnt;
}
int main()
{
    int k;
    string s;
    cin>>k>>s;

    int ans=atMost(s,k)-atMost(s,k-1);
    cout<<ans<<endl;
    
    return 0;
}