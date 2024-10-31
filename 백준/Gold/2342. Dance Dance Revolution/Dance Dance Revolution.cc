#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int costCheck(int from, int to) {
  if (from == 0) {
    return 2;
  }

  if (from == to) {
    return 1;
  }

  if ((from - to) % 2) {
    // 인접한 목적지라면
    return 3;
  } else {
    // 반대방향이라면
    return 4;
  }
}

int main() {
  int num;
  vector<int> v;

  while(true) {
    cin >> num;

    if (num == 0) {
      break;
    }

    v.push_back(num);
  }

  vector<vector<vector<int>>> dp(v.size() + 1, vector<vector<int>>(5, vector<int>(5, INF)));
  dp[0][0][0] = 0;

  for (int i = 0; i < v.size(); i++) {
    for (int a = 0; a < 5; a++) {
      for (int b = 0; b < 5; b++) {
        if (dp[i][a][b] != INF) {
          if (a != v[i]) {
            dp[i + 1][min(a, v[i])][max(a, v[i])] = min(dp[i][a][b] + costCheck(b, v[i]), dp[i + 1][min(a, v[i])][max(a, v[i])]);
          }
          if (b != v[i]) {
            dp[i + 1][min(b, v[i])][max(b, v[i])] = min(dp[i][a][b] + costCheck(a, v[i]), dp[i + 1][min(b, v[i])][max(b, v[i])]);
          }
        }
      }
    }
  }

  int rst = INF;
  for (int a = 0; a < 5; a++) {
    for (int b = 0; b < 5; b++) {
      rst = min(dp[v.size()][a][b], rst);
    }
  }

  cout << rst;

  return 0;
}