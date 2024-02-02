#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int visited[20001] = { 0, };

int bfs(vector<int> v[]) {
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    

    int now, cost;
    
    int max_cost = -1;
    int result = 1;
    while(!q.empty()) {
        now = q.front();
        cost = visited[now];
        q.pop();
        
        int next;
        for (int i = 0; i < v[now].size(); i++) {
            next = v[now][i];
            if (!visited[next]) {
                q.push(next);
                visited[next] = cost + 1;
                
                if (cost > max_cost) {
                    max_cost = cost;
                    result = 1;
                } else {
                    result++;
                }
            }
        }
    }
    
    return result;
}

int solution(int n, vector<vector<int>> edge) {
    
    vector<int> v[n + 1];
    
    for (int i = 0; i < edge.size(); i++) {
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    
    int answer = bfs(v);
    
    return answer;
}