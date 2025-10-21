#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    for (char ch : s)
    {
        if (ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch);//push the opening braces
        }
        else
        {   //when closing is encountered
            if (st.empty())
            {
                return false;
            }
            char top = st.top();
            st.pop();
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{'))
                return false;
        }
    }
    return st.empty();
}

int main()
{
    string s = "()[{]}";
    cout << isValid(s) << endl;

    return 0;
}