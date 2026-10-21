#include <bits/stdc++.h>
using namespace std;

int w, h;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs(pair<int, int> start, char target, vector<string>& maps) {
    queue<pair<int, int>> Q;
    int visited[102][102];
    for (int i = 0; i < h; i++) fill(visited[i], visited[i] + w, -1);

    Q.push(start);
    visited[start.second][start.first] = 0;

    while(!Q.empty()) {
        int x, y;
        tie(x, y) = Q.front(); Q.pop();

        if (maps[y][x] == target) {
            Q.push({x, y});
            return visited[y][x];
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
            if (maps[ny][nx] == 'X' || visited[ny][nx] > -1) continue;

            visited[ny][nx] = visited[y][x] + 1;
            Q.push({nx, ny});
        }
    }

    return -1;
}

int solution(vector<string> maps) {
    h = maps.size();
    w = maps[0].size();
    
    // find start
    int ans = 0;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (maps[y][x] == 'S') {
                int tmp = bfs({x, y}, 'L', maps);
                if (tmp == -1) return -1;
                ans += tmp;
                break;
            }
        }
    }

    // bfs (find exit)
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (maps[y][x] == 'L') {
                int tmp = bfs({x, y}, 'E', maps);
                if (tmp == -1) return -1;
                ans += tmp;
                break;
            }
        }
    }

    return ans;
}
