// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

bool isvowel(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return 1;
    return 0;
}
int maxVowels(string s, int k)
{
    long long sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += isvowel(s[i]) ? 1 : 0;
    }
    long long ma = 0;
    for (int i = k; i < s.size(); i++)
    {
        ma = max(ma, sum);
        sum += isvowel(s[i - k]) ? -1 : 0;
        sum += isvowel(s[i]) ? 1 : 0;
    }
    ma = max(ma, sum);
    return ma;
}
