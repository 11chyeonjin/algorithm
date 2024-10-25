#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define INF 987654321

using namespace std;

int maxCost = -1;

struct compare {
  bool operator() (pair<int,int> &a, pair<int,int> &b) {
    return a.second > b.second;
  }
};

int prim(int N, vector<vector<pair<int,int>>> &v) {
  vector<bool> visited(N + 1, false); // 
  priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq; // node, cost(오름차순)

  pq.push({1, 0});

  int totalCost = 0;
  
  while(!pq.empty()) {
    int curNode = pq.top().first;
    int curCost = pq.top().second;
    pq.pop();

    if (visited[curNode]) {
      continue;
    }

    visited[curNode] = true;
    totalCost += curCost;

    maxCost = max(curCost, maxCost);
    
    for (int i = 0; i < v[curNode].size(); i++) {
      int nextNode = v[curNode][i].first;
      int nextNodeCost = v[curNode][i].second;
      
      if (!visited[nextNode]) {
        pq.push({nextNode, nextNodeCost});
      }
    }
  }

  return totalCost;
}

int main() {
  // 길은 양방향. 길에는 양의 정수로 된 비용이 있음.
  // MST를 진행하고, 가장 큰 엣지를 없애기
  int N, M, a, b, c;
  cin >> N >> M;

  vector<vector<pair<int,int>>> v(N + 1);
  
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    
    v[a].push_back({b, c});
    v[b].push_back({a, c});
  }

  int result = prim(N, v);
  cout << result - maxCost;

  return 0;
}