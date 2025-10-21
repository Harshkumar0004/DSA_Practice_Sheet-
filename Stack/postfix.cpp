#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int postfix(vector<char>&arr){
    stack<int>stk;
    for(char i:arr){
        if(i<='9' && i>='0'){
            stk.push(i-'0');//push till you get numbers
        }
        else{
            //when operator is encountered
            if(stk.size()<2)
                return -1;
            int b=stk.top();
            stk.pop();
            int a=stk.top();
            stk.pop();
            
            switch (i)
            {

            //push new value after the calculations
            case '+':
                stk.push(a+b);
                break;
            case '-':
                stk.push(a-b);
                break;
            case '*':
                stk.push(a*b);
                break;
            case '/':
               stk.push(a/b);
               break;
            default:
                return -1;
            }
        }
    }
    return stk.top();//last element remaining is answer
}

int main(){
    vector<char>arr={'1','2','+','4','*'};
    cout<<postfix(arr)<<endl;
    return 0;
}