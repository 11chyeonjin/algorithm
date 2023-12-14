#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    queue<int> q;
    for (int i = 0; i < progresses.size(); i++) {
        if ((100 - progresses[i]) % speeds[i]) {
            q.push((100 - progresses[i]) / speeds[i] + 1);
        } else
            q.push((100 - progresses[i]) / speeds[i]);
    }
    
    vector<int> answer;
    while(!q.empty()) {
        int now_day = q.front();
        int tmp_ans = 1;
        q.pop();
        while(!q.empty()) {
            int next_day = q.front();
            if (next_day <= now_day) {
                tmp_ans++;
                q.pop();
            } else
                break;
        }
        answer.push_back(tmp_ans);
    }
    
    
    return answer;
}