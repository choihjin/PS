#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    for (int i = 0; i < static_cast<int>(priorities.size()); i++) {
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }

    int cnt = 0;
    while (!q.empty()) {
        int prior = q.front().first;
        int idx = q.front().second;
        q.pop();

        if (prior < pq.top()) {
            q.push({prior, idx});
            continue;
        }

        pq.pop();
        cnt++;
        if (idx == location) return cnt;
    }

    return -1;
}