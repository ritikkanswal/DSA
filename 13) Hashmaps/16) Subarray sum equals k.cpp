/// https://leetcode.com/problems/subarray-sum-equals-k/
//  https://leetcode.com/problems/binary-subarrays-with-sum/

// Method - 1
// BruteForce
// Time -> O(n3)

// Method - 2
// Optimised BruteForce
// Instead of calculating sum, store the sum in prefix array
// Time -> O(n2) Space -> O(n)

// Method - 3
// Optimised BruteForce
// Instead of calculating sum and storing in prefix array, use sum variable
// Time -> O(n2) Space -> O(1)

// Method - 4
// HashMap
// Time -> O(n) Space -> O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>ump;
        int cnt=0,sum=0;
        ump[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(ump[sum-k])
            {
                cnt+=ump[sum-k];
            }
            ump[sum]++;
        }
        return cnt;
    }
};