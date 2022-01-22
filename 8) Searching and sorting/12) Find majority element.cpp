// https://leetcode.com/problems/majority-element/

// Method - 1
int majorityElement(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}

//Method-2
//Moore voting algo
int majorityElement(vector<int> &nums)
{
    int cnt = 0;
    int mj = 0;
    for (auto x : nums)
    {
        if (cnt == 0)
            mj = x;
        if (mj == x)
            cnt++;
        else
            cnt--;
    }
    return mj;
}