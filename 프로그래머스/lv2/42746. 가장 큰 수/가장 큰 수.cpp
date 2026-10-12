#include <bits/stdc++.h>
using namespace std;

bool compare(string& a, string& b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string ans = "";
    vector<string> ns;

    // sorting
    for (const auto& n : numbers) ns.push_back(to_string(n));
    sort(ns.begin(), ns.end(), compare);
    
    // make answer
    for (int i = 0; i < ns.size(); i++) {
        if (ans == "0") break;
        ans += ns[i];
    }

    return ans;
}