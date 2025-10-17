#include<iostream>
#include<vector>
using namespace std;

bool searchmatrix(vector<vector<int>> &matrix, int target)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        if (matrix[i][0] <= target &&
            matrix[i][matrix[i].size() - 1] >= target)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == target)
                    return true;
            }
        }
    }
    return false;
}

int main(){
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout<<searchmatrix(matrix, 5)<<endl;
    return 0;
    
}