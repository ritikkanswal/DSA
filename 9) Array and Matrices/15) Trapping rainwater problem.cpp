

// Method-1
// Time - O(n)
// Space - O(n)
int trap(vector<int> &height)
{
    int n = height.size();
    int prefix[n];
    int suffix[n];
    int ma = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        prefix[i] = ma;
        ma = max(ma, height[i]);
    }
    ma = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        suffix[i] = ma;
        ma = max(ma, height[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int val = min(prefix[i], suffix[i]) - height[i];
        if (val > 0)
            sum += val;
    }
    return sum;
}

// Method-2
// Time - O(n)
// Space - O(1)

int trap(vector<int> &height)
{
    int left = 0, right = height.size() - 1;
    int sum = 0;
    int maxLeft = 0, maxRight = 0;
    while (left <= right)
    {
        if (height[left] <= height[right])
        {
            if (height[left] > maxLeft)
                maxLeft = height[left];
            else
                sum += maxLeft - height[left];
            left++;
        }
        else
        {
            if (height[right] > maxRight)
                maxRight = height[right];
            else
                sum += maxRight - height[right];
            right--;
        }
    }
    return sum;
}