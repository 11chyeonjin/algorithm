#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define INF 987654321
using namespace std;

int dist[101] = { 0, };
bool selected[101] = { false };

int solution(int n, vector<vector<int>> costs) {
    vector<pair<int,int>> v[n];
    for (int i = 0; i < costs.size(); i++) {
        v[costs[i][0]].push_back({costs[i][1], costs[i][2]});
        v[costs[i][1]].push_back({costs[i][0], costs[i][2]}); 
    }
    
    int answer = 0;
    fill(dist, dist + n, INF);
    
    dist[0] = 0;
    
    selected[0] = true;
    for (int i = 0; i < v[0].size(); i++) {
        dist[v[0][i].first] = v[0][i].second;
    }
    
    for (int i = 0; i < n - 1; i++) { // E = V - 1 = N - 1 => 0 ~ n-2
        int min_cost = INF;
        int min_index = -1;
        
        for (int j = 0; j < n; j++) {
            if (selected[j])
                continue;
            
            if (min_cost > dist[j]) {
                min_cost = dist[j];
                min_index = j;
            }
        }
        selected[min_index] = true;
        cout << min_cost << "\n";
        answer += min_cost;
        
        for (int j = 0; j < v[min_index].size(); j++) {
            int next = v[min_index][j].first;
            int next_dist = v[min_index][j].second;
            
            if (selected[next])
                continue;
            
            dist[next] = min(dist[next], next_dist);
        }
    }
    
    return answer;
}