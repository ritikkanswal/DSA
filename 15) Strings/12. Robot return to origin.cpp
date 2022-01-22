

bool judgeCircle(string moves)
{
    int x = 0, y = 0;
    for (auto ch : moves)
    {
        x = (ch == 'L') ? x - 1 : x;
        x = (ch == 'R') ? x + 1 : x;
        y = (ch == 'U') ? y + 1 : y;
        y = (ch == 'D') ? y - 1 : y;
    }
    if (x == 0 and y == 0)
        return 1;
    return 0;
}



