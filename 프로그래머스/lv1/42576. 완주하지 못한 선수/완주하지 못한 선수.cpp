#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_multiset<string> s(participant.begin(), participant.end());
    for (const auto& c : completion) s.erase(s.find(c));
    
    return *s.begin();
}