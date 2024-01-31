#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dp[10001];

int main() {
  cin >> N;

  dp[0] = 0;
  for (int i = 1; i <= N; i++) {
    cin >> dp[i];
  }

  for (int i = 2; i <= N; i++) { // i 번째 카드 dp 계산
    for (int j = 1; j < i; j++) {
      dp[i] = max(dp[i], dp[j] + dp[i - j]);
    }
  }

  cout << dp[N];

  return 0;
}