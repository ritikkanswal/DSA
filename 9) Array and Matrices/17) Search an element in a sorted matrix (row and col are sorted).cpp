// https://leetcode.com/problems/search-a-2d-matrix-ii/

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int r = matrix.size();
    int c = matrix[0].size();

    int x = 0;
    int y = c - 1;
    while (x < r and y >= 0)
    {
        if (matrix[x][y] == target)
            return 1;
        else if (matrix[x][y] < target)
            x++;
        else
            y--;
    }
    return 0;
}