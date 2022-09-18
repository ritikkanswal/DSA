// https://leetcode.com/problems/continuous-subarray-sum/

class Solution
{
public:
    int sum = 0, ma = INT_MIN;
    for (auto x : nums)
    {
        sum += x;
        ma = max(ma, sum);
        if (sum < 0)
            sum = 0;
    }
    return ma;
};