#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

// 한 시작점에서 각 정점으로의 최단 경로.
// 방향성이 존재하므로, 다익스트라 사용.

int V, E, K;
vector<pair<int, int>> user[20001];
int minCost[20001];

struct comp {
  bool operator()(pair<int, int> p1, pair<int, int> p2) {
    return p1.first > p2.first;
  }
};

void func(int start) {
  priority_queue<pair<int, int>, vector<pair<int,int>>, comp> pq;
  pq.push({0, start}); // w, 정점
  minCost[start] = 0;

  while(!pq.empty()) {
    int now_w = pq.top().first;
    int now = pq.top().second;
    pq.pop();
    for (int i = 0; i < user[now].size(); i++) {
      int next_w = user[now][i].first;
      int next = user[now][i].second;
      if (minCost[next] > now_w + next_w) {
        minCost[next] = now_w + next_w;
        pq.push({minCost[next], next});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> V >> E >> K;
  int from, to, w;
  for (int i = 0; i < E; i++) {
    cin >> from >> to >> w;
    user[from].push_back({w, to});
  }

  fill(minCost, minCost + 20002, INF);

  func(K);

  for (int i = 1; i <= V; i++) {
    if (minCost[i] == INF)
      cout << "INF\n";
    else
      cout << minCost[i] << "\n";
  }

  return 0;
}