#include <bits/stdc++.h>

using namespace std;

int to_minutes(string t) {
    return stoi(t.substr(0,2)) * 60 + stoi(t.substr(3));
}

int calculate_fee(const vector<int>& fees, int time) {
    if (time <= fees[0]) return fees[1];
    else {
        return fees[1] + ((time - fees[0] + fees[2] - 1) / fees[2]) * fees[3];
    }
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> ans;
    map<string, int> cumulative_time;
    unordered_map<string, int> in_park;
    
    // calculate cumulative time
    for (const auto& r : records) {
        string time = r.substr(0, 5);
        string car_num = r.substr(6, 4);
        string inout = r.substr(11);
        
        if (inout == "IN") {
            in_park[car_num] = to_minutes(time);
        }
        else if (inout == "OUT") {
            cumulative_time[car_num] += to_minutes(time) - in_park[car_num];
            in_park.erase(car_num);
        }
    }
    
    // in case of not OUT
    for (const auto& i : in_park) {
        cumulative_time[i.first] += to_minutes("23:59") - i.second;
    }
    
    // calculate parking fee
    for (const auto& c : cumulative_time) {
        ans.push_back(calculate_fee(fees, c.second));
    }
    
    return ans;
}