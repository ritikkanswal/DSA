// https://leetcode.com/problems/most-common-word/

map<string, int> mp1, mp2;
string RemovePunctuation(string word)
{
    for (int i = 0; i < word.size(); i++)
    {
        if (ispunct(word[i]))
            word[i] = ' ';
    }
    return word;
}
string mostCommonWord(string p, vector<string> &banned)
{
    p = RemovePunctuation(p);
    for (auto x : banned)
    {
        mp1[x] = 1;
    }
    int ma = 0;
    stringstream ss(p);
    string word;
    while (ss >> word)
    {
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        if (mp1[word] == 0)
            mp2[word]++;
    }
    string res;
    for (auto x : mp2)
    {
        if (x.second > ma)
        {
            res = x.first;
            ma = x.second;
        }
    }
    return res;
}