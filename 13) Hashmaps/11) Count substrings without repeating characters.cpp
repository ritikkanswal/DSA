/// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/hashmap-and-heaps/count-of-substrings-having-all-unique-characters-official/ojquestion

// TestCase s = "abba"
// Substrings would be "a", "ab", "b", "b", "ba", "a"
// Total = 6

// Method - 1
// Bruteforce
// Time -> O(n3)

// Method - 2
// set + sliding window
// Time -> O(2n)

class Solution
{
public:
    int CountOfLongestSubstring(string s)
    {
        unordered_set<char> st;
        int l = 0, r = 0;
        int len = 0, n = s.size();

        while (r < n)
        {
            while (st.find(s[r]) != st.end())
            {
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            len += r - l + 1;
            r++;
        }
        return len;
    }
};

// Method - 3 (Optimised method - 2)
// HashMap + sliding window
// Time -> O(n)

class Solution
{
public:
    int CountOfLongestSubstring(string s)
    {
        vector<int> m(256, -1);
        int l = 0, r = 0;
        int len = 0, n = s.size();

        while (r < n)
        {
            if (m[s[r]] != -1)
                l = max(m[s[r]] + 1, l);

            m[s[r]] = r;
            len += r - l + 1;
            r++;
        }
        return len;
    }
};