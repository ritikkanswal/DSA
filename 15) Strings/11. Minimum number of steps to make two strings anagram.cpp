// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

int minSteps(string s, string t)
{
    map<int, int> mp1;
    int sum = 0;
    for (auto x : s)
    {
        mp1[x]++;
    }

    for (auto x : t)
    {
        mp1[x]--;
    }

    for (auto x : mp1)
    {
        if (x.second > 0)
            sum += x.second;
    }
    return sum;
}