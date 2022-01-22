

//Method-1
//Time -O(n*k)
int findTheWinner(int n, int k)
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    while (q.size() != 1)
    {
        int x = k;
        while (x > 1)
        {
            int r = q.front();
            q.pop();
            q.push(r);
            x--;
        }
        q.pop();
    }
    return q.front();
}

//Method-2
//Time -O(n)
//SPace -O(n)

int fun(int n, int k)
{
    if (n == 0)
        return 0;
    return (fun(n - 1, k) + k) % n;
}
int findTheWinner(int n, int k)
{
    return fun(n, k) + 1;
}

//Method-3
//Time -O(n)
//SPace -O(1)

int findTheWinner(int n, int k)
{
    int res = 0;
    for (int i = 1; i <= n; ++i)
        res = (res + k) % i;
    return res + 1;
}