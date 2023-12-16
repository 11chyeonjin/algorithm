#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 987654321;
using namespace std;

struct comp {
    bool operator()(pair<int,int> p1, pair<int,int> p2) {
        return p1.first > p2.first;
    }
};

bool visited[101] = { false, };

int solution(int n, vector<vector<int>> costs)  {
    vector<pair<int, int>> v[n];
    for (int i = 0; i < costs.size(); i++) {
        v[costs[i][0]].push_back({costs[i][1], costs[i][2]});
        v[costs[i][1]].push_back({costs[i][0], costs[i][2]});
    }

    int answer = 0;
    
    priority_queue<pair<int, int>, vector<pair<int,int>>, comp> pq; // dist, next_index
    visited[0] = true;
    for (int i = 0; i < v[0].size(); i++) {
        pq.push({v[0][i].second, v[0][i].first}); // dist, next_index
    }
    
    while(!pq.empty()) {
        int dist = pq.top().first;
        int idx = pq.top().second;
        pq.pop();
        
        if (!visited[idx]) {
            visited[idx] = true;
            answer += dist;
            
            for (int i = 0; i < v[idx].size(); i++) {
                if (!visited[v[idx][i].first])
                    pq.push({v[idx][i].second, v[idx][i].first});
            }
        }
    }
    
    
    return answer;
}