#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int N, M, start, goal;
vector<pair<int, int>> user[1001];

bool comp(pair<int, int> p1, pair<int, int> p2) {
  return p1.first < p2.first;
}

int minCost[1001];

void dijkstra() {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  minCost[start] = 0;
  pq.push({0, start});
  while (!pq.empty()) {
    int now_cost = pq.top().first;
    int now = pq.top().second;
    pq.pop();
    for (int i = 0; i < user[now].size(); i++) {
      int next_cost = user[now][i].first;
      int next = user[now][i].second;
      if (minCost[next] > minCost[now] + next_cost) {
        minCost[next] = minCost[now] + next_cost;
        pq.push({next_cost, next});
      }
    }
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  int from, to, cost;
  for (int i = 0; i < M; i++) {
    cin >> from >> to >> cost;
    user[from].push_back({cost, to});
  }
  cin >> start >> goal;

  for (int i = 0; i < 1001; i++) {
    sort(user[i].begin(), user[i].end(), comp);
  }
  fill(minCost, minCost + 1002, INF);

  dijkstra();

  cout << minCost[goal];

  return 0;
}