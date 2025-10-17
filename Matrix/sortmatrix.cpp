#include<iostream>
#include<vector>
#include<map>

using namespace std;

//counting sort
vector<int> sortArray(vector<int> &nums)
{
    map<int, int> mp;
    for (int i : nums)
        mp[i]++;
    vector<int> res;
    for (auto it : mp)
    {
        int k = it.second;
        while (k > 0)
        {
            res.emplace_back(it.first);
            k--;
        }
    }
    return res;
}
void sortmatrix(vector<vector<int>> &mat){
    vector<int>temp;
    //gather elements
    for(auto it:mat){
        for(auto it2:it){
            temp.emplace_back(it2);
        }
    }
    temp=sortArray(temp);//sort them
    int r=mat.size(),c=mat[0].size(),k=0;
    //replace in the old array
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            mat[i][j]=temp[k];
            k++;
        }
    }

}

int main(){
    vector<vector<int>>mat={{5,1,6},{2,4,0},{9,11,3}};
    sortmatrix(mat);
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}