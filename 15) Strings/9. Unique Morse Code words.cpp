// https://leetcode.com/problems/unique-morse-code-words/

int uniqueMorseRepresentations(vector<string> &words)
{
    vector<string> v = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    set<string> s;
    for (auto x : words)
    {
        string tmp;
        for (auto ch : x)
        {
            tmp += v[ch - 'a'];
        }
        s.insert(tmp);
    }
    return s.size();
}