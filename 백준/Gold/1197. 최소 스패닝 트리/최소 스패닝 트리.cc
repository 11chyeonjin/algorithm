#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int V, E;
bool selected[10001] = { false, };

struct comp {
  bool operator()(pair<int,int> p1, pair<int,int> p2) {
    return p1.first > p2.first;
  }
};

int main() {
  cin >> V >> E;
  int from, to, cost;

  int answer = 0;

  vector<pair<int,int>> v[V + 1];

  for (int i = 0; i < E; i++) {
    cin >> from >> to >> cost;
    v[from].push_back({to, cost});
    v[to].push_back({from, cost});
  }

  priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;
  selected[1] = true;
  for (int i = 0; i < v[1].size(); i++) {
    pq.push({v[1][i].second, v[1][i].first}); // cost, 이동 정점
  }

  while(!pq.empty()) {
    int min_cost = pq.top().first;
    int now_V = pq.top().second;
    pq.pop();

    if (!selected[now_V]) {
      selected[now_V] = true;
      answer += min_cost;

      for (int i = 0; i < v[now_V].size(); i++) {
        if (!selected[v[now_V][i].first]) { // 이동 정점
          pq.push({v[now_V][i].second, v[now_V][i].first}); // cost, 이동 정점
        }
      }
    }
  }

  cout << answer;

  return 0;
}