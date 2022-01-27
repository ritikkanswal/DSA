// https://leetcode.com/problems/roman-to-integer/

int find(char x)
{
    if (x == 'I')
        return 1;
    if (x == 'V')
        return 5;
    if (x == 'X')
        return 10;
    if (x == 'L')
        return 50;
    if (x == 'C')
        return 100;
    if (x == 'D')
        return 500;
    if (x == 'M')
        return 1000;

    return -1;
}
int romanToInt(string s)
{
    long long sum = find(s[s.size() - 1]);
    for (int i = s.size() - 1; i > 0; i--)
    {
        if (find(s[i]) > find(s[i - 1]))
        {
            sum -= find(s[i - 1]);
        }
        else if (find(s[i]) <= find(s[i - 1]))
        {
            sum += find(s[i - 1]);
        }
    }
    return sum;
}