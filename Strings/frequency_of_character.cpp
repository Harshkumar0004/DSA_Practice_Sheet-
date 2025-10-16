#include<iostream>
#include<map>
#include<string>

using namespace std;

map<char,int>freqcnt(string &str){
    map<char,int>mp;
    for(char c:str)mp[c]++;

    return mp;
}

int main(){
    string str="takeuforward";
    map<char,int>mp=freqcnt(str);
    for(auto it:mp){
        cout<<it.first<<" "<<it.second<<endl;

    }
    return 0;

}