// Method - 1
// Rotate the string and check whether it is equal to another string
// Time -> O(n2)

// Method - 2
// Using Queue

int rotateString(string s, string s2)
{
    if (s.size() != s2.size())
        return 0;
    queue<char> q1, q2;
    int k = s2.size();

    for (int i = 0; i < s.size(); i++)
        q1.push(s[i]);

    for (int i = 0; i < s2.size(); i++)
        q2.push(s2[i]);

    while (k--)
    {
        char ch = q2.front();
        q2.pop();
        q2.push(ch);
        if (q2 == q1)
            return 1;
    }
    return 0;
}