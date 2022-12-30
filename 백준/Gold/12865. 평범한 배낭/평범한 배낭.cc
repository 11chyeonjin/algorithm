#include <iostream>
using namespace std;
#define endl "\n";

int N, K, W, V;

int Weight[101];
int Value[101];
int dp[101][100001] = { 0 };

int main() {
  cin >> N >> K;
  for (int i = 1; i <= N; i++) {
    cin >> W >> V;
    Weight[i] = W;
    Value[i] = V;
  }

  for (int i = 1; i <= N; i++) { // i 번째 물건을 고려하여 dp 수정
    for (int j = 1; j <= K; j++) { // j 무게일 때 최대 가치를 파악
      if (Weight[i] <= j)
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - Weight[i]] + Value[i]);
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  
  cout << dp[N][K];

  return 0;
}