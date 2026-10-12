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

    // edge case (all numbers are 0)
    if (ns[0] == "0") return "0";

    // make answer
    for (const auto& n : ns) ans += n;

    return ans;
}