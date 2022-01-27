// https://leetcode.com/problems/ransom-note/

//Time:O(nlogn)
//Space:O(1)
bool canConstruct(string r, string m)
{
    int i = 0, j = 0;
    sort(r.begin(), r.end());
    sort(m.begin(), m.end());
    while (i < r.size() and j < m.size())
    {
        if (r[i] == m[j])
            i++, j++;
        else
            j++;
    }
    if (i == r.size())
        return 1;
    return 0;
}

//Time:O(n)
//Space:O(1)
bool canConstruct(string r, string m)
{
    unordered_map<char, int> map(26);
    for (int i = 0; i < m.size(); i++)
        map[m[i]]++;
    for (int j = 0; j < r.size(); j++)
        if (--map[r[j]] < 0)
            return 0;
    return 1;
}