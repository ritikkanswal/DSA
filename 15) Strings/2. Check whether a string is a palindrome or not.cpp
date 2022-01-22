// https://practice.geeksforgeeks.org/problems/palindrome-string0817/1
// Method - 1
// Using auxillary space

// Method - 2
class Solution
{
public:
    int isPalindrome(string S)
    {
        int i = 0, j = S.size() - 1;
        while (i < j)
        {
            if (S[i++] != S[j--])
                return 0;
        }
        return 1;
    }
};