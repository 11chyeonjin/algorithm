#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;

int max_cost = 0;
int max_idx = 1;

void bfs(int start, vector<pair<int,int>>* v) {
  queue<pair<int,int>> q;
  vector<bool> visited(n + 1, false);

  q.push({0, start});
  visited[start] = true;

  int cur;
  int cur_cost;
  
  while(!q.empty()) {
    cur_cost = q.front().first;
    cur = q.front().second;
    q.pop();

    if (max_cost < cur_cost) {
      max_cost = cur_cost;
      max_idx = cur;
    }

    for (int i = 0; i < v[cur].size(); i++) {
      if (!visited[v[cur][i].second]) {
        q.push({cur_cost + v[cur][i].first, v[cur][i].second});
        visited[v[cur][i].second] = true;
      }
    }
  }
}

int main() {
  cin >> n;

  vector<pair<int,int>> v[n + 1];
  
  int from, to, cost;
  for (int i = 0; i < n - 1; i++) {
    cin >> from >> to >> cost;
    v[from].push_back({cost, to});
    v[to].push_back({cost, from});
  }

  bfs(1, v);

  bfs(max_idx, v);

  cout << max_cost;

  return 0;
}