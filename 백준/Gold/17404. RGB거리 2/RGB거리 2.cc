#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int N;

int dp_func(vector<vector<int>>& v, int num) {
  vector<vector<int>> dp(N, vector<int>(3));
  for (int i = 0; i < 3; i++) {
    dp[0][i] = INF;
  }
  dp[0][num] = v[0][num];

  for (int i = 1; i < N - 1; i++) {
    dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + v[i][0];
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + v[i][1];
    dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + v[i][2];
  }

  dp[N - 1][0] = min(dp[N - 2][1], dp[N - 2][2]) + v[N - 1][0];
  dp[N - 1][1] = min(dp[N - 2][0], dp[N - 2][2]) + v[N - 1][1];
  dp[N - 1][2] = min(dp[N - 2][0], dp[N - 2][1]) + v[N - 1][2];

  dp[N - 1][num] = INF;

  return min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2]));
}

int main() {
  /*
    1. DP, 직전 집의 색과 첫번째 집의 색을 계속 가지고 가야함.
  */

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;

  vector<vector<int>> v(N, vector<int>(3));
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> v[i][j];
    }
  }

  cout << min(dp_func(v, 0), min(dp_func(v, 1), dp_func(v, 2)));

  return 0;
}