#include <iostream>
#include <vector>
using namespace std;

bool searchmatrix(vector<vector<int>> &matrix, int target)
{
    int r = matrix.size();
    int c = matrix[0].size();
    int i = 0, j = c - 1;
    while (i < r && j >= 0)
    {
        if (matrix[i][j] == target)
            return true;
        //reduce the search space
        else if (matrix[i][j] > target)
            j--;
        else
            i++;
    }

    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    cout << searchmatrix(matrix, 5) << endl;
    return 0;
}