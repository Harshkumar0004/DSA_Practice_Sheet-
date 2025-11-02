#include <iostream>
#include <vector>
using namespace std;

void setzeroes(vector<vector<int>>& matrix){
    int m = matrix.size(), n = matrix[0].size();
    vector<int> row(m,0), col(n,0);

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(matrix[i][j]==0){
                row[i]=1;
                col[j]=1;
            }

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(row[i]||col[j])
                matrix[i][j]=0;
}

int main(){
    vector<vector<int>> matrix={{1,1,1},{1,0,1},{1,1,1}};
    setzeroes(matrix);
    for(auto &r:matrix){
        for(auto &c:r) cout<<c<<" ";
        cout<<endl;
    }
}
