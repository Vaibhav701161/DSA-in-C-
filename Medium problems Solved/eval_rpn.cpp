// eval_rpn.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Stack-based evaluation of postfix expression.
*/

int evalRPN(vector<string>& tokens){
    stack<int> st;
    for(auto&t:tokens){
        if(t=="+"||t=="-"||t=="*"||t=="/"){
            int b=st.top();st.pop();
            int a=st.top();st.pop();
            if(t=="+") st.push(a+b);
            else if(t=="-") st.push(a-b);
            else if(t=="*") st.push(a*b);
            else st.push(a/b);
        }else st.push(stoi(t));
    }
    return st.top();
}

int main(){
    vector<string> expr={"2","1","+","3","*"};
    cout<<"RPN Result: "<<evalRPN(expr)<<'\n';
}
