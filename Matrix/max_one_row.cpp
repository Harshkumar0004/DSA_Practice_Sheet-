#include<iostream>
#include<vector>
using namespace std;
vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
{
    vector<int> res = {-1, -1};
    for (int i = 0; i < mat.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < mat[0].size(); j++)
        {
            if (mat[i][j] == 1)
            {
                cnt++;
            }
        }
        if (cnt > res[1])
        {
            res[0] = i;
            res[1] = cnt;
        }
    }
    return res;
}

int main(){
    vector<vector<int>> mat = {{0,1,1,0},{0,0,1,1},{1,0,0,0}};
    vector<int>res=rowAndMaximumOnes(mat);
    for(int i:res){
        cout<<i<<" ";
    }
    return 0;
}
