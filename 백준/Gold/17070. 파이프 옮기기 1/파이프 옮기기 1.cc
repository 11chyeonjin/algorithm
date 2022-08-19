#include <iostream>
using namespace std;

int dp[16][16][3] = { 0 }; // 대각선2, 가로0, 세로1
int pipe[16][16];

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  
  int in;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> in;
      pipe[i][j] = in;
    }
  }

  dp[0][1][0] = 1;
  
  for (int i = 2; i < N; i++) {
    if (pipe[0][i])
      continue;;
    dp[0][i][0] = dp[0][i-1][0];
  }

  for (int i = 1; i < N; i++) {
    for (int j = 2; j < N; j++) {
      if (pipe[i][j])
        continue;
      if (!(pipe[i-1][j] || pipe[i][j-1]))
        dp[i][j][2] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2]; // 대각선 파이프
      dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j][2];  // 세로 파이프
      dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][2];  // 가로 파이프
    }
  }

  cout << dp[N-1][N-1][0] + dp[N-1][N-1][1] + dp[N-1][N-1][2];

  return 0;
}