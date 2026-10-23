#include <bits/stdc++.h>
using namespace std;

int bfs(int n, const int network[][102]) {
    int visited[102] = {0};
    queue<int> Q;
    
    int cnt = 0;
    Q.push(1);
    visited[1] = 1;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        cnt++;

        for (int i = 1; i <= n; i++) {
            if (!network[cur][i]) continue; // disconnected
            if (visited[i]) continue; // already visited

            Q.push(i);
            visited[i] = 1;
        }
    }

    return abs(cnt - (n - cnt));
}

int solution(int n, vector<vector<int>> wires) {
    int ans = 101;

    // make network grpah
    int network[102][102] = {0};
    for (const auto& w : wires) {
        network[w[0]][w[1]] = 1;
        network[w[1]][w[0]] = 1;
    }

    // brute force + bfs
    for (const auto& w : wires) {
        network[w[0]][w[1]] = 0;
        network[w[1]][w[0]] = 0;

        ans = min(ans, bfs(n, network));

        network[w[0]][w[1]] = 1;
        network[w[1]][w[0]] = 1;
    }

    return ans;
}
