#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums) 
{
    unordered_set<int> s(nums.begin(), nums.end());

    if (s.size() < nums.size() / 2) return s.size();
    return nums.size() / 2;
}