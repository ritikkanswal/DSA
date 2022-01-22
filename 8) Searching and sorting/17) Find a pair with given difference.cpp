// https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/

// Method-1
int countKDifference(vector<int> &nums, int k)
{
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (abs(nums[i] - nums[j]) == k)
                cnt++;
        }
    }
    return cnt;
}

//Method-2
int countKDifference(vector<int> &nums, int k)
{
    unordered_map<int, int> map;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (map[nums[i] + k])
            count += map[nums[i] + k];
        if (map[nums[i] - k])
            count += map[nums[i] - k];
        map[nums[i]]++;
    }
    return count;
}

//Method-3 (counting sort)

int countKDifference(vector<int> &nums, int k)
{
    int map[101] = {0};
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        map[nums[i]]++;
    }
    for (int i = k + 1; i < 101; i++)
    {
        count += map[i] * map[i - k];
    }
    return count;
}
