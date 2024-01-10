#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, M, X;
int costs[2][1001];
vector<pair<int,int>> v[2][1001];

struct comp {
  bool operator() (pair<int,int> p1, pair<int,int> p2) {
    return p1.first > p2.first;
  }
};

void dijkstra(int num) {
  priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq; // {cost, v}
  fill(&costs[num][0], &costs[num][N + 1], INF);
  pq.push({0, X}); // {cost 0, 기준 정점 X}
  costs[num][X] = 0;

  while(!pq.empty()) {
    int now_cost = pq.top().first; // cost
    int now_v = pq.top().second; // v
    pq.pop();

    for (int i = 0; i < v[num][now_v].size(); i++) {
      int next_v = v[num][now_v][i].first; // v
      int next_cost = v[num][now_v][i].second; // cost

      if (costs[num][next_v] > now_cost + next_cost) { // 적은 값으로 갱신이 가능하다면,
        costs[num][next_v] = now_cost + next_cost;
        pq.push({costs[num][next_v], next_v}); // {cost, v}
      }
    }
  }
}

int main() {
  // X번 마을을 기준으로 다익스트라 진행

  cin >> N >> M >> X;
  
  int from, to, cost;
  for (int i = 0; i < M; i++) {
    cin >> from >> to >> cost;
    v[0][from].push_back({to, cost});
    v[1][to].push_back({from, cost});
  }

  dijkstra(1);
  dijkstra(0);

  int ans = -1;
  for (int i = 1; i <= N; i++) {
    ans = max(ans, costs[0][i] + costs[1][i]);
  }

  cout << ans;

  return 0;
}