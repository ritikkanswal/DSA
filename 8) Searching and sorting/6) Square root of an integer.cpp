// https://leetcode.com/problems/sqrtx

int binary_search(int x)
{
    int l = 0, h = x;
    while (l <= h)
    {
        long long mid = l + (h - l) / 2;
        if (mid * mid == x)
            return mid;
        else if (mid * mid < x)
        {
            if ((mid + 1) * (mid + 1) > x)
                return mid;
            else
                l = mid + 1;
        }
        else
            h = mid - 1;
    }
    return 0;
}
int mySqrt(int x)
{
    return binary_search(x);
}