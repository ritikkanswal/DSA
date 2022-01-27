bool visited[52][52];
int dfs(vector<vector<int>> &grid, int x, int y)
{
    int r = grid.size();
    int c = grid[0].size();
    if (x < 0 or y < 0 or x >= r or y >= c or visited[x][y] or grid[x][y] == 0)
        return 0;
    visited[x][y] = 1;
    return 1 + dfs(grid, x + 1, y) + dfs(grid, x, y + 1) + dfs(grid, x - 1, y) + dfs(grid, x, y - 1);
}
int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int r = grid.size();
    int c = grid[0].size();
    int ma = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (!visited[i][j] and grid[i][j] == 1)
                ma = max(ma, dfs(grid, i, j));
        }
    }
    return ma;
}