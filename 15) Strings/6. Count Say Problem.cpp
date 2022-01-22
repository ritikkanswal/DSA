// https://leetcode.com/problems/count-and-say/

//Method-1 (recursive)
//T.C -: O(n)
//S.C -: O(n)
string countAndSay(int n)
{
    if (n == 1)
        return "1";
    string res = countAndSay(n - 1);
    int i = 0, j = res.size();
    string ans;
    while (i < j)
    {
        int count = 1;
        while ((i + 1) < j and res[i] == res[i + 1])
        {
            count++;
            i++;
        }
        ans += to_string(count) + res[i];
        i++;
    }
    return ans;
}

//Method-2 (without Recursive)
//T.C -: O(n)
//S.C -: O(1)
string countAndSay(int n)
{
    if (n == 0)
        return "";
    string res = "1";
    while (--n)
    {
        string cur = "";
        for (int i = 0; i < res.size(); i++)
        {
            int count = 1;
            while ((i + 1 < res.size()) && (res[i] == res[i + 1]))
            {
                count++;
                i++;
            }
            cur += to_string(count) + res[i];
        }
        res = cur;
    }
    return res;
}