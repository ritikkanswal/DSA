// https://leetcode.com/problems/add-binary/

string addBinary(string num1, string num2)
{
    int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
    string res;
    int sum = 0;
    while (i >= 0 || j >= 0 || carry)
    {
        sum = carry;
        sum += i >= 0 ? num1[i--] - '0' : 0;
        sum += j >= 0 ? num2[j--] - '0' : 0;
        int ans = sum % 2;
        carry = sum / 2;
        res += ans + '0';
    }
    reverse(res.begin(), res.end());
    return res;
}