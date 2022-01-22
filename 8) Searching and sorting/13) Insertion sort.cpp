// https://leetcode.com/problems/sort-an-array

vector<int> InsertionSort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        int j = i;
        int key = nums[i];
        while (j >= 1 and nums[j - 1] > key)
        {
            nums[j] = nums[j - 1];
            j--;
        }
        nums[j] = key;
    }
    return nums;
}

