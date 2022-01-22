// https://practice.geeksforgeeks.org/problems/maximum-no-of-1s-row3027/1/#

int binarySearch(vector<int> nums)
{
    int l = 0, r = nums.size() - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] == 0)
        {
            if (mid == nums.size() - 1)
                return mid;
            if ((mid + 1) < nums.size() and nums[mid + 1] == 1)
                return mid;
        }
        if (nums[mid] == 0)
            l = mid + 1;
        else if (nums[mid] == 1)
            r = mid - 1;
    }
    return -1;
}
int maxOnes(vector<vector<int>> &Mat, int N, int M)
{
    int ma = 0, idx = 0;
    for (int i = 0; i < N; i++)
    {
        int x = M - binarySearch(Mat[i]) - 1;
        if (x > ma)
        {
            ma = x;
            idx = i;
        }
    }
    return idx;
}