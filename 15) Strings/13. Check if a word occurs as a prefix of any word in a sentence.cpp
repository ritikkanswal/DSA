// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/

// Using StringStream
int isPrefixOfWord(string sentence, string searchWord)
{
    stringstream ss(sentence);
    string word;
    int k = 0;
    while (ss >> word)
    {
        k++;
        string tmp = word.substr(0, searchWord.size());
        if (word.size() >= searchWord.size())
            if (tmp == searchWord)
                return k;
    }
    return -1;
}