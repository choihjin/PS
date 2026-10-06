#include <bits/stdc++.h>
using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> s;

    for (const auto& p : phone_book) {
        for (int i = 0; i < p.size(); i++) {
            s.insert(p.substr(0, i));
        }
    }

    for (const auto& p : phone_book) {
        if (s.find(p) != s.end()) return false;
    }
    
    return true;
}