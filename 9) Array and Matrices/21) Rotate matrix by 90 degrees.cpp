// https://leetcode.com/problems/rotate-image/

void rotate(vector<vector<int>> &matrix)
{
    int r = matrix.size();
    int c = matrix[0].size();
    //STEP-1 Transpose it
    //STEP-2 Reverse Row wise
    for (int i = 0; i < r; i++)
    {
        for (int j = i; j < c; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < r; i++)
        reverse(matrix[i].begin(), matrix[i].end());
}

