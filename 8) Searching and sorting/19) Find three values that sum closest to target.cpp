// https://leetcode.com/problems/3sum-closest/

int threeSumClosest(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int mi = INT_MAX, res;
    for (int i = 0; i < nums.size() - 2; i++)
    {
        int left = i + 1, right = nums.size() - 1;
        while (left < right)
        {
            int tmp = (nums[i] + nums[left] + nums[right]);
            if (tmp > target)
                right--;
            else
                left++;
            if (mi > abs(tmp - target))
            {
                mi = abs(tmp - target);
                res = tmp;
            }
        }
    }
    return res;
}