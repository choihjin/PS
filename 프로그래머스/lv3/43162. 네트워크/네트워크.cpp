#include <string>
#include <vector>

using namespace std;

int visited[202];

void dfs(int idx, int n, const vector<vector<int>>& computers) {
    for (int i = 0; i < n; i++) {
        if (computers[idx][i] && !visited[i]) {
            visited[i] = 1;
            dfs(i, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int ans = 0;
    fill(begin(visited), end(visited), 0);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            dfs(i, n, computers);
            ans++;
        }
    }

    return ans;
}
