#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int ans = 1;
    unordered_map<string, int> m;

    for (const auto& c : clothes) 
        m[c[1]]++;

    for (const auto& n : m)
        ans *= (n.second + 1);

    return ans - 1;
}