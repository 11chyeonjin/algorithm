#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int, int> um;
    for (int i = 0; i < nums.size(); i++) {
        if (um.find(nums[i]) == um.end()) {
            um.insert({nums[i], 1});
        } else {
            um[nums[i]] = um[nums[i]] + 1;
        }
    }

    return min(nums.size() / 2, um.size());
}