// https://leetcode.com/problems/longest-uncommon-subsequence-i/

int findLUSlength(string a, string b)
{
    return a == b ? -1 : max(a.size(), b.size());
}