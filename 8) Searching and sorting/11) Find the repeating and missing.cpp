// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/

// Method 1 (Use Sorting)
// Approach: 
// Sort the input array.
// Traverse the array and check for missing and repeating.
// Method-2
int *findTwoElement(int *arr, int n)
{
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
        mp[i + 1]++;
    }
    int s1, s2;
    for (auto x : mp)
    {
        if (x.second == 3)
            s1 = x.first;
        else if (x.second == 1)
            s2 = x.first;
    }
    int *res = new int(2);
    res[0] = s1;
    res[1] = s2;
    return res;
}

//Method-3
int *findTwoElement(int *arr, int n)
{
    int xor1 = 0;
    for (int i = 0; i < n; i++)
    {
        xor1 ^= (arr[i] ^ (i + 1));
    }
    int set_bit = (xor1 & (~(xor1 - 1)));
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++)
    {
        if ((i + 1) & set_bit)
            s1 ^= (i + 1);
        else
            s2 ^= (i + 1);
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & set_bit)
            s1 ^= (arr[i]);
        else
            s2 ^= (arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == s2)
        {
            swap(s1, s2);
            break;
        }
    }
    int *res = new int(2);
    res[0] = s1;
    res[1] = s2;
    return res;
}
