#include <bits/stdc++.h>
using namespace std;

bool compare1(pair<int, string> a, pair<int, string> b) {
    return a.first > b.first;
}

bool compare2(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) return a.first > b.first;
    else return a.second < b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> ans;
    
    // sorting with total genres
    unordered_map<string, int> tot_plays;
    for (int i = 0; i < genres.size(); i++) {
        tot_plays[genres[i]] += plays[i];
    }

    vector<pair<int, string>> plays_sorted;
    for (const auto& s : tot_plays) {
        plays_sorted.push_back({s.second, s.first});
    }
    sort(plays_sorted.begin(), plays_sorted.end(), compare1);    

    // sorting with same plays
    unordered_map<string, vector<pair<int, int>>> songs;
    for (int i = 0; i < genres.size(); i++) {
        songs[genres[i]].push_back({plays[i], i});
    }
    for (auto& s : songs) {
        sort(s.second.begin(), s.second.end(), compare2);
    }

    // make answer vector
    for (const auto& p : plays_sorted) {
        ans.push_back(songs[p.second][0].second);
        if (songs[p.second].size() > 1) ans.push_back(songs[p.second][1].second);
    }

    return ans;
}