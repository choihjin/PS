#include <bits/stdc++.h>

using namespace std;

int calculate_time(string in, string out) {
    int in_m = stoi(in.substr(0,2)) * 60 + stoi(in.substr(3));
    int out_m = stoi(out.substr(0,2)) * 60 + stoi(out.substr(3));
    
    return out_m - in_m;
}

int calculate_fee(const vector<int>& fees, int time) {
    if (time < fees[0]) return fees[1];
    else {
        return fees[1] + ((time - fees[0] + fees[2] - 1) / fees[2]) * fees[3];
    }
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> ans;
    map<string, int> cumulative_time;
    unordered_map<string, string> in_park;
    
    // calculate cumulative time
    for (const auto& r : records) {
        string time = r.substr(0, 5);
        string car_num = r.substr(6, 4);
        string inout = r.substr(11);
        
        if (inout == "IN") {
            in_park[car_num] = time;
        }
        else if (inout == "OUT") {
            cumulative_time[car_num] += calculate_time(in_park[car_num], time);
            in_park.erase(car_num);
        }
    }
    
    // in case of not OUT
    for (const auto& i : in_park) {
        cumulative_time[i.first] += calculate_time(i.second, "23:59");
    }
    
    // calculate parking fee
    for (const auto& c : cumulative_time) {
        ans.push_back(calculate_fee(fees, c.second));
    }
    
    return ans;
}