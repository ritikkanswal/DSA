// https://leetcode.com/problems/length-of-last-word/

int Size(string s, int i)
{
    if (s[i] == NULL)
        return 0;
    return 1 + Size(s, i + 1);
}
int lengthOfLastWord(string s)
{
    stringstream ss(s);
    string word;
    int ma = 0;
    while (ss >> word)
    {
        ma = Size(word, 0);
    }
    return ma;
}