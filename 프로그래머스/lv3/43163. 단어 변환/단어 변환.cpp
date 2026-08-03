#include <bits/stdc++.h>
using namespace std;

int count_diff(const string& a, const string& b) {
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            if (++cnt > 1) return cnt;
        }
    }
    return cnt;
}

int solution(string begin, string target, vector<string> words) {
    words.insert(words.begin(), begin);

    // make graph
    int graph[52][52] = {};
    for (int i = 0; i < words.size(); i++) {
        for (int j = i + 1; j < words.size(); j++) {
            if (i == j) continue;
            if (count_diff(words[i], words[j]) == 1) {
                graph[i][j] = 1;
                graph[j][i] = 1;
            }
        }
    }

    // bfs
    int begin_idx = 0;
    int target_idx = find(words.begin(), words.end(), target) - words.begin();
    queue<pair<int, int>> Q;
    int visited[52] = {};

    Q.push({begin_idx, 0});
    visited[begin_idx] = 1;
    while(!Q.empty()) {
        int cur, dis;
        tie(cur, dis) = Q.front(); Q.pop();

        // exit
        if (cur == target_idx) return dis;

        for (int nxt = 0; nxt < words.size(); nxt++) {
            if (!graph[cur][nxt] || visited[nxt]) continue;
    
            Q.push({nxt, dis + 1});
            visited[nxt] = 1;
        }
    }

    return 0;
}