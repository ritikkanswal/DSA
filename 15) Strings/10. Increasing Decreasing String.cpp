// https://leetcode.com/problems/increasing-decreasing-string/

//Method-1
string sortString(string s)
{
    map<char, int> mp;
    for (auto x : s)
    {
        mp[x]++;
    }
    string res;
    while (res.size() != s.size())
    {
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (it->second > 0)
            {
                res += it->first;
                it->second--;
            }
        }

        for (auto it = mp.rbegin(); it != mp.rend(); it++)
        {
            if (it->second > 0)
            {
                res += it->first;
                it->second--;
            }
        }
    }
    return res;
}

//Method-2

string sortString(string s, string res = "")
{
    int cnt[26] = {};
    for (auto ch : s)
        ++cnt[ch - 'a'];
    while (s.size() != res.size())
    {
        for (auto i = 0; i < 26; ++i)
            res += string(--cnt[i] >= 0 ? 1 : 0, 'a' + i);
        for (int i = 25; i >= 0; --i)
            res += string(--cnt[i] >= 0 ? 1 : 0, 'a' + i);
    }
    return res;
}