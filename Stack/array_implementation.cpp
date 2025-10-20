#include<iostream>
#include<vector>
using namespace std;

#define MAX 100
class stack{
    int arr[MAX];
    int top;
    public:
    stack(){top=-1;}
    void push(int val){
        if(top==MAX-1){
            cout<<"Overflow !!"<<endl;
            return;
        }
        arr[top]=val;
        top++;
    }
    void pop(){
        if(top==-1){
            cout<<"Underflow !!"<<endl;
            return;
        }
        top--;
    }
    bool isempty(){return top==-1;}


};

int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.pop();

    //10-20-30
}