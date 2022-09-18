/// https://leetcode.com/problems/subarrays-with-k-different-integers/

// count of substrings with exactly k distinct characters =
// number of substrings with less than equal to k distinct characters  -  number of substrings with less than equal to k-1 distinct characters

//Time Complexity : O(n)
//Space Complexity : O(1)


class Solution {
public:
    int atMost(vector<int>& nums, int k)
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
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return atMost(nums,k)-atMost(nums,k-1);
    }
};