#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> ans;

    reverse(progresses.begin(), progresses.end());
    reverse(speeds.begin(), speeds.end());
    while (!progresses.empty()) {
        for (size_t i = 0; i < progresses.size(); i++)
            progresses[i] += speeds[i];

        if (progresses.back() >= 100) {
            int cnt = 0;
            while (!progresses.empty() && progresses.back() >= 100) {
                progresses.pop_back();
                speeds.pop_back();
                cnt++;
            }
            ans.push_back(cnt);
        }
    }

    return ans;
}
