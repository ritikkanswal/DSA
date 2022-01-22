// https://leetcode.com/problems/valid-parentheses/

bool isValid(string s)
{
    stack<char> st;
    for (auto x : s)
    {
        if (x == '(' || x == '{' || x == '[')
            st.push(x);
        else
        {
            if (st.size() == 0)
                return false;
            if (x == ')' and st.top() == '(' || (x == '}' and st.top() == '{') || x == ']' and st.top() == '[')
                st.pop();
            else
                return false;
        }
    }
    return st.size() == 0;
}