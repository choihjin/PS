#include <bits/stdc++.h>
using namespace std;

bool dfs(
    const vector<vector<string>>& tickets,
    vector<bool>& used,
    vector<string>& ans
) { 
    // base condition
    if (ans.size() == tickets.size() + 1) return true;

    string cur = ans.back();

    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] != cur || used[i]) continue;

        ans.push_back(tickets[i][1]);
        used[i] = true;

        if(dfs(tickets, used, ans)) return true;

        ans.pop_back();
        used[i] = false;
    }

    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> ans;
    vector<bool> used(tickets.size(), false);
    sort(tickets.begin(), tickets.end());
    
    ans.push_back("ICN");
    dfs(tickets, used, ans);

    return ans;
}