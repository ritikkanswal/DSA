https://leetcode.com/problems/defanging-an-ip-address/


//Method-1
//T.C -: O(n)
//S.C -: O(n)
string defangIPaddr(string address)
{
    string res;
    for (auto x : address)
    {
        if (x == '.')
            res += "[.]";
        else
            res += x;
    }
    return res;
}

//Method-2
//T.C -: O(n)
//S.C -: O(1)
string defangIPaddr(string address)
{
    for (int i = address.size() - 2; i >= 0; i--)
        if (address[i + 1] == '.')
            address = address.substr(0, i + 1) + "[.]" + address.substr(i + 2);
    return address;
}