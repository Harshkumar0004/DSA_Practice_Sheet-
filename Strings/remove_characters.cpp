#include<iostream>
#include<string>

using namespace std;

string removechar(string &str){
    string nstr="";
    for(int i=0;i<str.size();i++){
        if(isalpha(str[i]))nstr+=str[i];

    }
    return nstr;
}

int main(){
    string str="1ax 8q  wq  6526rfcdc61 c15q/";
    string res=removechar(str);
    cout<<res<<endl;
    return 0;
}