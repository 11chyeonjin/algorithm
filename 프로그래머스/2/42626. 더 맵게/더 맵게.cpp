#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    
    int ff = 0;
    int ss = 0;
    
    int answer = 0;
    
    while(true) {
        ff = pq.top();
        if (ff < K) {
            pq.pop();
            
            if (pq.empty())
                return -1;
            
            ss = pq.top();
            pq.pop();
            pq.push(ff + ss * 2);
            
            answer++;
        } else
            break;
    }
    
    
    
    return answer;
}