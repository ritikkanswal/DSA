#include <bits/stdc++.h>
#define mod 1000000007
#define lli long long int
using namespace std;
int countMaximumOperations(string s, string t)
{
    map<int, int> mp1, mp2;

    for (auto x : s)
    {
        mp1[x]++;
    }

    for (auto x : t)
    {
        mp2[x]++;
    }
    int mi = INT_MAX;
    for (auto x : mp1)
    {

        if (x.second >= mp2[x.first])
        {
            mi = min(mi, x.second / mp2[x.first]);
        }
    }
    return mi;
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout<<countMaximumOperations(s1,s2)<<endl;
    return 0;
}