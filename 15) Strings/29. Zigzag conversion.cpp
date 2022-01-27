// https://leetcode.com/problems/zigzag-conversion/

string convert(string s, int numRows)
{
    if (numRows == 1)
        return s;
    string res;
    vector<string> v(numRows);
    int k = 0;
    int ch = -1;
    numRows--;
    for (int i = 0; i < s.size(); i++)
    {
        v[k] += s[i];
        if (k % numRows == 0)
            ch *= -1;
        if (ch == 1)
            k++;
        else
            k--;
    }
    for (auto x : v)
    {
        res += x;
    }
    return res;
}

string convert(string s, int numRows)
{
    if (numRows == 1)
        return s;
    string res;
    vector<string> v(numRows);
    int k = 0, ch = -1;
    numRows--;
    for (int i = 0; i < s.size(); i++)
    {
        v[k] += s[i];
        ch = k % numRows == 0 ? ch * -1 : ch;
        k = (ch == 1) ? k + 1 : k - 1;
    }
    for (auto x : v)
        res += x;
    return res;
}