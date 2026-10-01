#include <bits/stdc++.h>
using namespace std;

int solution(int bridge_length, int limit, vector<int> wait) {
    int time = 0;
    int sum = 0;

    reverse(wait.begin(), wait.end());
    deque<int> bridge(bridge_length);

    while (1) {
        if (wait.empty() && sum == 0) break;

        sum -= bridge.front();
        bridge.pop_front();

        if (!wait.empty() && sum + wait.back() <= limit) {
            bridge.push_back(wait.back());
            sum += wait.back();
            wait.pop_back();
        }
        else {
            bridge.push_back(0);
        }

        time++;
    }

    return time;
}