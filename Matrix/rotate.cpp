#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{   // transpose the matrix

    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // reverse each row of the matrix

    for (int i = 0; i < matrix.size(); i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main(){
    vector<vector<int>>mat={{0,1,1},{0,0,1},{1,0,0}};
    rotate(mat);
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}