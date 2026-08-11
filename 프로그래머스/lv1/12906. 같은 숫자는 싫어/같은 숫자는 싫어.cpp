#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> ans;
    ans.push_back(arr[0]);

    for (auto a : arr) {
        if (a != ans.back()) ans.push_back(a);
    }

    return ans;
}
