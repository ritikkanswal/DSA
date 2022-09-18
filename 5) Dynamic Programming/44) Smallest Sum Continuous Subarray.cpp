// https://practice.geeksforgeeks.org/problems/smallest-sum-contiguous-subarray/1/


class Solution{
  public:
  int smallestSumSubarray(vector<int>& nums){
      
       int sum=0,mi=INT_MAX;
       for(auto x:nums)
       {
           sum+=x;
           mi=min(mi,sum);
           if(sum>0) sum=0;
       }
        return mi;
  }
};