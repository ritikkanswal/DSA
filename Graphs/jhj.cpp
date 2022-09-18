#include <bits/stdc++.h>
using namespace std;

pair<int, int> u, l;

bool check(int i, int j, int n)
{
    if (i >= n or j >= n)
        return true;

    if (j >= u.second and j <= l.second and i >= u.first and i <= l.first)
        return true;

    return false;
}

int main()
{
    int n, x;
    cin >> n >> x;

    pair<int, int> m(n / 2, n / 2);

    u.first = (m.first - x);
    u.second = (m.first - x);

    l.first = (m.second + x);
    l.second = (m.second + x);

    int dp[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i == 0 or j == 0) and !check(i, j, n))
            {
                dp[i][j] = 1;
            }
            else
            {
                int total = 0;
                if (check(i, j, n))
                    continue;

                if (!check(i - 1, j, n))
                    total += dp[i - 1][j];

                if (!check(i, j - 1, n))
                    total += dp[i][j - 1];

                dp[i][j] = total;
            }
        }
    }
    cout << dp[n - 1][n - 1] << endl;
}