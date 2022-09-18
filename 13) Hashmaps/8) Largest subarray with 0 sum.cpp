/// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1#

// Method - 1
// Bruteforce
// Time -> O(n2)

// Method - 2
// Hashmap
// Time -> O(n) Space -> O(n)

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int>ump;
        int sum=0;
        int k=1;
        int ma=0;
        ump[sum]=k++;
        for(auto x:A)
        {
            sum+=x;
            if(ump[sum])
                ma=max(ma,k-ump[sum]);
            else
            ump[sum]=k;
            k++;
        }
        return ma;
    }
};