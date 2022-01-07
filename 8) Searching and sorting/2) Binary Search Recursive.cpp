// https://leetcode.com/problems/binary-search

int binarysearch(vector<int> &nums, int target, int i, int j)
{
    if (i > j)
        return -1;
    int mid = i + (j - i) / 2;
    if (nums[mid] == target)
        return mid;
    if (nums[mid] < target)
        return binarysearch(nums, target, mid + 1, j);
    else
        return binarysearch(nums, target, i, mid - 1);
}
int search(vector<int> &nums, int target)
{
    return binarysearch(nums, target, 0, nums.size() - 1);
}