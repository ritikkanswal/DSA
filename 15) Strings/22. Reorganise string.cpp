// https://leetcode.com/problems/reorganize-string/

//Time:O(n)
//Space:O(n)
string reorganizeString(string s)
{
    map<int, int> mp;
    for (auto x : s)
    {
        mp[x]++;
    }
    pair<int, int> p = {0, 0};
    for (auto x : mp)
    {
        if (p.second < x.second)
        {
            p.second = x.second;
            p.first = x.first;
        }
    }
    if (p.second > (s.size() + 1) / 2)
        return "";
    string res = s;
    int i = 0;
    for (i = 0; p.second; i += 2)
    {
        p.second--;
        res[i] = p.first;
    }
    mp[p.first] = 0;
    for (auto x : mp)
    {
        while (x.second != 0)
        {
            if (i >= s.size())
            {
                i = 1;
                continue;
            }
            res[i] = x.first;
            x.second--;
            i += 2;
        }
    }
    return res;
}


//Time:O(nlogn)
//Space:O(n)

class Solution
{
public:
    string reorganizeString(string s)
    {
        if (s.size() == 1)
            return s;
        string res;
        priority_queue<pair<int, int>> pq;
        map<int, int> mp;
        for (auto x : s)
            mp[x]++;
        for (auto x : mp)
            pq.push({x.second, x.first});
        while (!pq.empty())
        {
            pair<int, int> p1, p2;
            p1 = pq.top();
            pq.pop();
            res += p1.second;
            if (!pq.empty())
            {
                p2 = pq.top();
                pq.pop();
                res += p2.second;
                if (p2.first - 1 != 0)
                    pq.push({p2.first - 1, p2.second});
            }
            if (p1.first - 1 != 0)
                pq.push({p1.first - 1, p1.second});
        }
        for (int i = 1; i < res.size(); i++)
        {
            if (res[i] == res[i - 1])
                return "";
        }
        return res;
    }
};