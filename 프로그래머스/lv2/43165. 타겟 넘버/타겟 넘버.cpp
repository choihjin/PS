#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int ans;

void dfs(int idx, int sum, const vector<int>& numbers, int target) {
    if (idx == numbers.size()) {
        if (sum == target) ans++;
        return;
    }

    dfs(idx + 1, sum + numbers[idx], numbers, target);
    dfs(idx + 1, sum - numbers[idx], numbers, target);
}

int solution(vector<int> numbers, int target) {
    ans = 0;
    dfs(0, 0, numbers, target);
    return ans;
}