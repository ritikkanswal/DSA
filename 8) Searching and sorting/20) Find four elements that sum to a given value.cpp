// https://leetcode.com/problems/4sum/

map<vector<int>, int> mp;
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    if (nums.size() < 4)
        return {};
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 3; i++)
    {
        for (int j = i + 1; j < nums.size() - 2; j++)
        {
            int left = j + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                long long tmp = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                if (tmp == target)
                {
                    if (mp[{nums[i], nums[j], nums[left], nums[right]}] == 0)
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                    mp[res[res.size() - 1]]++;
                }
                if (tmp > target)
                    right--;
                else
                    left++;
            }
        }
    }
    return res;
}