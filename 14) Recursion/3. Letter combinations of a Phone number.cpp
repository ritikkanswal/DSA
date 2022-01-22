// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

map<char, vector<char>> mp;
vector<string> res;
void fun(string digits, int i, string r)
{
    if (i == digits.size())
    {
        if (r.size())
            res.push_back(r);
        return;
    }
    string s;
    for (auto x : mp[digits[i]])
    {
        fun(digits, i + 1, r + x);
    }
}
vector<string> letterCombinations(string digits)
{
    mp['2'] = {'a', 'b', 'c'};
    mp['3'] = {'d', 'e', 'f'};
    mp['4'] = {'g', 'h', 'i'};
    mp['5'] = {'j', 'k', 'l'};
    mp['6'] = {'m', 'n', 'o'};
    mp['7'] = {'p', 'q', 'r', 's'};
    mp['8'] = {'t', 'u', 'v'};
    mp['9'] = {'w', 'x', 'y', 'z'};
    fun(digits, 0, "");
    return res;
}