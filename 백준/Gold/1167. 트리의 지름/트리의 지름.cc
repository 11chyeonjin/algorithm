#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int V;

bool visited[100001] = { false, };

int node_bfs(int start, vector<pair<int,int>> v[]) {
  int max_cost = -1;
  int result_node = -1;
  queue<pair<int, int>> q;
  q.push({start, 0});
  visited[start] = true;

  int now, now_cost;
  while(!q.empty()) {
    now = q.front().first;
    now_cost = q.front().second;
    if (now_cost >= max_cost) {
      max_cost = now_cost;
      result_node = now;
    }
    q.pop();

    for (int i = 0; i < v[now].size(); i++) {
      if (!visited[v[now][i].first]) {
        q.push({v[now][i].first, now_cost + v[now][i].second});
        visited[v[now][i].first] = true;
      }
    }
  }

  return result_node;
}

int sol_bfs(int start, vector<pair<int,int>> v[]) {
  int result = -1;
  fill(visited, visited + V + 1, false);
  queue<pair<int, int>> q;
  q.push({start, 0});
  visited[start] = true;

  int now, now_cost;
  while(!q.empty()) {
    now = q.front().first;
    now_cost = q.front().second;
    result = max(now_cost, result);
    q.pop();
    
    for (int i = 0; i < v[now].size(); i++) {
      if (!visited[v[now][i].first]) {
        q.push({v[now][i].first, now_cost + v[now][i].second});
        visited[v[now][i].first] = true;
      }
    }
  }

  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> V;
  vector<pair<int,int>> v[V + 1]; // {to, cost}

  int from, to, cost;
  for (int i = 0; i < V; i++) {
    cin >> from;
    while(true) {
      cin >> to;
      if (to == -1)
        break;

      cin >> cost;
      v[from].push_back({to, cost});
    }
  }

  int tmp = node_bfs(1, v);

  cout << sol_bfs(tmp, v);

  return 0;
}