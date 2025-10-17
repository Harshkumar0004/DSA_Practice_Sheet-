#include<iostream>
using namespace std;
//use long long to tackle overflow

//reverse the number
long long rev(long long n){
    long long s=0;
    while(n>0){
        long long d=n%10;
        s=s*10+d;
        n/=10;
    }
    return s;
}

//rasie to power
long long powr(long long n,long long p){
    long long result=1;
    while(p>0){
        result*=n;
        p--;
    }
    return result;
}

int main(){
    long long num=12;
    long long p=rev(num);
    cout<<powr(num,p)<<endl;
    return 0;
}