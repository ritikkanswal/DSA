// https://leetcode.com/problems/spiral-matrix/

vector<int> res;
int minR = 0, maxR = matrix.size() - 1;
int minC = 0, maxC = matrix[0].size() - 1;
int zs = (maxR + 1) * (maxC + 1);
int count = 0;
while (count < zs)
{
    //left to right
    for (int j = minC, i = minR; j <= maxC and count < zs; j++)
    {
        res.push_back(matrix[i][j]);
        count++;
    }
    minR++;

    //top to down
    for (int i = minR, j = maxC; i <= maxR and count < zs; i++)
    {
        res.push_back(matrix[i][j]);
        count++;
    }
    maxC--;

    //right to left
    for (int j = maxC, i = maxR; j >= minC and count < zs; j--)
    {
        res.push_back(matrix[i][j]);
        count++;
    }
    maxR--;

    //bottom to up
    for (int i = maxR, j = minC; i >= minR and count < zs; i--)
    {
        res.push_back(matrix[i][j]);
        count++;
    }
    minC++;
}
return res;