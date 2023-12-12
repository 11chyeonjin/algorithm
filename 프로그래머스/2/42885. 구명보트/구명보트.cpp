#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    
    int f_index = 0;
    int answer = 0;
    while (f_index < people.size()) {
        if (f_index != people.size() - 1 && people[f_index] + people[people.size() - 1] <= limit) {
            answer++;
            f_index++;
        } else {
            answer++;
        }
        people.pop_back();
    }
    
    return answer;
}