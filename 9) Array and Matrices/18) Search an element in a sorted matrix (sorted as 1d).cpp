// https://leetcode.com/problems/search-a-2d-matrix/

// Method-1
// Search linearly
// Time:O(n^2)

//Method-2
// Time :O(n)

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

//Method-3

// Time : O(log(n))

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    // x=n%r
    // y=n/r;
    // 0,1,2,3...
    bool BinarySearch(vector<vector<int>> & matrix, int left, int right, int target)
    {
        if (left > right)
            return false;
        int c = matrix[0].size();
        int mid = (left + right) / 2;
        int y = mid % c;
        int x = mid / c;
        // cout<<matrix[x][y]<<endl;
        if (matrix[x][y] == target)
            return true;
        else if (matrix[x][y] < target)
            return BinarySearch(matrix, mid + 1, right, target);
        else
            return BinarySearch(matrix, left, mid - 1, target);
    }
    bool searchMatrix(vector<vector<int>> & matrix, int target)
    {
        int r = matrix.size();
        int c = matrix[0].size();
        return BinarySearch(matrix, 0, r * c - 1, target);
    }
}