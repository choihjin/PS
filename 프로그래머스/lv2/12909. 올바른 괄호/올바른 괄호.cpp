#include<bits/stdc++.h>
using namespace std;

bool solution(string s)
{
    stack<char> stk;
    for (char c : s) {
        if (c == '(') stk.push('(');
        else {
            if (stk.empty()) return false;
            stk.pop();
        }
    }
    
    return stk.empty();
}
