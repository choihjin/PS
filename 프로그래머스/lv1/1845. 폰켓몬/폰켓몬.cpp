#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums) 
{
    int ans = 0;
    
    map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
        if (m.find(nums[i]) != m.end()) 
            m[nums[i]]++;
        else 
            m.insert({nums[i], 1});
    }

    if (m.size() < nums.size() / 2) return m.size();
    return nums.size() / 2;
}