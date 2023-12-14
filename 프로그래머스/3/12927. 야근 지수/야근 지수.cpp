#include <string>
#include <vector>
#include <queue>
using namespace std;

// 이분 탐색 아이디어
long long solution(int n, vector<int> works) {
    priority_queue<int, vector<int>> pq; // 기본 내림차순 정렬
    
    for (int i = 0; i < works.size(); i++) {
        pq.push({works[i]});
    }
    
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (pq.empty())
            return 0;
        
        t = pq.top();
        if (t != 0) {
            pq.pop();
            pq.push(t - 1);
        } else
            return 0;
    }
    
    long long answer = 0;
    while(!pq.empty()) {
        answer += pq.top() * pq.top();
        pq.pop();
    }
    return answer;
}