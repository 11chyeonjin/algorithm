#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct comp {
    bool operator() (pair<int, int> p1, pair<int, int> p2) {
        return p1.first < p2.first;
    }
};

vector<int> solution(vector<int> prices) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq; // value, index
    
    vector<int> answer(prices.size());
    
    for (int i = 0; i < prices.size(); i++) {
        while(!pq.empty()) {
            if (pq.top().first > prices[i]) {
                answer[pq.top().second] = i - pq.top().second;
                pq.pop();
            } else
                break;
        }
        pq.push({prices[i],i});
    }
    
    while(!pq.empty()) {
        answer[pq.top().second] = prices.size() - 1 - pq.top().second;
        pq.pop();
    }
    
    return answer;
}