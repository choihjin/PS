#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());

    int ans = 0;
    for (; ans < citations.size(); ans++) {
        if (citations[ans] < ans + 1) break;
    }

    return ans;
}