#include <bits/stdc++.h>
using namespace std;

bool compare(int& a, int& b) {
    return a > b;
}

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), compare);

    int ans = 0;
    for (; ans < citations.size(); ans++) {
        if (citations[ans] < ans + 1) break;
    }

    return ans;
}