/*
 * DAY 35: Valid Parentheses
 *
 * Problem Statement:
 * Given a string s containing just '(', ')', '{', '}', '[', ']', determine
 * if the input string is valid. A string is valid if every open bracket is
 * closed by the same type of bracket in the correct order.
 *
 * Approach:
 * Use a stack. Push opening brackets onto the stack. When encountering a
 * closing bracket, check if the top of stack matches. If not, return false.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char top = st.top(); st.pop();
            if (c == ')' && top != '(') return false;
            if (c == '}' && top != '{') return false;
            if (c == ']' && top != '[') return false;
        }
    }
    return st.empty();
}

int main() {
    cout << isValid("()[]{}") << endl;  // 1 (true)
    cout << isValid("(]") << endl;       // 0 (false)
    cout << isValid("{[()]}") << endl;   // 1 (true)
    return 0;
}
