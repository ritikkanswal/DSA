// https : //leetcode.com/problems/first-unique-character-in-a-string/

//Method-1
int firstUniqChar(string s)
{
    map<char, int> mp;
    int res = -1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        mp[s[i]]++;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (mp[s[i]] == 1)
            return i;
    }
    return -1;
}

//Method-2
int firstUniqChar(string s)
{
    vector<int> v(26, 0);
    for (char c : s)
        v[c - 'a']++;
    for (int i = 0; i < s.length(); i++)
    {
        if (v[s[i] - 'a'] == 1)
            return i;
    }
    return -1;
}