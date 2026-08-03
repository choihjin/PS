#include<bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> maps)
{
    queue<tuple<int, int, int>> Q; // x, y, distance
    int visited[102][102] = {};
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};

    int x = 0, y = 0, dis = 1;
    visited[x][y] = 1;
    Q.push({x, y, dis});
    int n = maps.size();
    int m = maps[0].size();

    while(!Q.empty()) {
        tie(x, y, dis) = Q.front();
        Q.pop();

        if(x == n - 1 && y == m - 1) return dis;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (visited[nx][ny] || !maps[nx][ny]) continue;
            Q.push({nx, ny, dis + 1});
            visited[nx][ny] = 1;
        }
    }

    return -1;
}
