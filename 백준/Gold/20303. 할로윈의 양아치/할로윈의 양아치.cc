#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
  그룹 단위로 사탕 수를 저장하고
  그 배열을 가지고 냅색을 진행
*/

void bfs(int startKid, vector<int> &kids, vector<vector<int>> &friends, vector<pair<int, int>> &groups) {
  int candySum = 0;

  queue<int> q;
  vector<bool> visited(kids.size(), false);

  q.push(startKid);
  visited[startKid] = true;
  
  int kidCount = 0;

  while(!q.empty()) {
    int curKid = q.front();
    q.pop();
    candySum += kids[curKid];
    kids[curKid] = 0; // 사탕 수를 0으로 재할당
    kidCount++;
    
    for (int i = 0; i < friends[curKid].size(); i++) {
      int nextKid = friends[curKid][i];
      if (!visited[nextKid]) {
        q.push(nextKid);
        visited[nextKid] = true;
      }
    }
  }

  groups.push_back({candySum, kidCount});
}

int main() {
  // 입력 부분
  int N, M, K;
  // 아이들 수, 친구 관계 수, 울음공명 최소 아이 수
  cin >> N >> M >> K;

  vector<int> kids(1, 0);

  int candy;
  for (int i = 1; i <= N; i++) {
    cin >> candy;
    kids.push_back(candy);
  }

  vector<vector<int>> friends(N + 1);
  int from, to;

  for (int i = 0; i < M; i++) {
    cin >> from >> to;
    friends[from].push_back(to);
    friends[to].push_back(from);
  }

  vector<pair<int, int>> groups; // {사탕, 친구}

  for (int i = 1; i <= N; i++) {
    if (kids[i]) {
      bfs(i, kids, friends, groups);
    }
  }

  vector<vector<int>> dp(groups.size(), vector<int> (K + 1, 0));

  for (int j = 1; j <= K; j++) {
    if (j > groups[0].second) {
      dp[0][j] = groups[0].first;
    }
  }

  for (int i = 1; i < groups.size(); i++) { // 그룹별로
    for (int j = 1; j <= K; j++) { // 무게별로
      if (j > groups[i].second) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - groups[i].second] + groups[i].first);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  cout << dp[groups.size() - 1][K];

  return 0;
}