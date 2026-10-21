#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> maps) {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int h = maps.size();
    int w = maps[0].size();
    int tl; // time for L

    queue<pair<int, int>> sl; // stack for L
    queue<pair<int, int>> se; // stack for E
    int visited[102][102];
    for (int i = 0; i < h; i++) fill(visited[i], visited[i] + w, -1);
    
    // find start
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (maps[y][x] == 'S') {
                sl.push({x, y});
                visited[y][x] = 0;
                break;
            }
        }
    }

    // bfs (find leber)
    while(!sl.empty()) {
        int x, y;
        tie(x, y) = sl.front(); sl.pop();

        if (maps[y][x] == 'L') {
            se.push({x, y});
            tl = visited[y][x];

            for (int i = 0; i < h; i++) fill(visited[i], visited[i] + w, -1);
            visited[y][x] = 0;

            break;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
            if (maps[ny][nx] == 'X' || visited[ny][nx] > -1) continue;

            visited[ny][nx] = visited[y][x] + 1;
            sl.push({nx, ny});
        }
    }

    // bfs (find exit)
    while(!se.empty()) {
        int x, y;
        tie(x, y) = se.front(); se.pop();

        if (maps[y][x] == 'E') 
            return tl + visited[y][x];

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
            if (maps[ny][nx] == 'X' || visited[ny][nx] > -1) continue;

            visited[ny][nx] = visited[y][x] + 1;
            se.push({nx, ny});
        }
    }

    return -1;
}
