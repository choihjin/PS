#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {

    // make map
    int board[102][102] = {}; // 1: can move
    for (const auto& rect : rectangle) {
        for (int i = 2 * rect[0]; i <= 2 * rect[2]; i++) {
            for (int j = 2 * rect[1]; j <= 2 * rect[3]; j++) {
                if ((i == 2 * rect[0] || i == 2 * rect[2] || j == 2 * rect[1] || j == 2 * rect[3]) && board[i][j] != -1)  board[i][j] = 1;
                else board[i][j] = -1;
            }
        }
    }

    // bfs
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    queue<tuple<int, int, int>> q;
    int visited[102][102] = {};

    q.push({2 * characterX, 2 * characterY, 0});
    visited[2 * characterX][2 * characterY] = 1;
    while(!q.empty()) {
        int x, y, dist;
        tie(x, y, dist) = q.front(); q.pop();

        if (x == 2 * itemX && y == 2 * itemY) return dist / 2;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= 102 || ny < 0 || ny >= 102) continue;
            if (board[nx][ny] != 1 || visited[nx][ny]) continue;

            q.push({nx, ny, dist + 1});
            visited[nx][ny] = 1;
        }
    }

    return 0;
}
