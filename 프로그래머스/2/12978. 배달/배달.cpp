#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int dist[51];

struct comp {
    bool operator()(pair<int,int> p1, pair<int,int> p2) {
        return p1.first > p2.first;
    }
};

int solution(int N, vector<vector<int>> road, int K) {
    vector<pair<int,int>> v[N + 1];
    for (int i = 0; i < road.size(); i++) {
        v[road[i][0]].push_back({road[i][1], road[i][2]});
        v[road[i][1]].push_back({road[i][0], road[i][2]});
    }
    
    priority_queue<pair<int, int>, vector<pair<int,int>>, comp> pq; // {cost, v} / first인 cost 기준으로 오름차순 정렬
    fill(dist, dist + 1 + N, INF);
    pq.push({0, 1});
    dist[1] = 0;
    
    while(!pq.empty()) {
        int now_cost = pq.top().first;
        int now_v = pq.top().second;
        pq.pop();
        
        for (int i = 0; i < v[now_v].size(); i++) {
            int next_v = v[now_v][i].first;
            int next_cost = v[now_v][i].second;
            
            if (dist[next_v] > now_cost + next_cost) {
                dist[next_v] = now_cost + next_cost;
                pq.push({dist[next_v], next_v});
            }
        }
    }
    
    int answer = 0;
    
    for (int i = 1; i <= N; i++) {
        if (dist[i] <= K) {
            cout << i << " ";
            answer++;
        }
    }

    return answer;
}