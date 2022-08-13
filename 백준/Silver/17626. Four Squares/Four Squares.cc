#include <iostream>
using namespace std;

int dp[50001] = { 0 };

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i < 224; i++) {
    dp[i * i] = 1;
  }
  for (int i = 2; i <= 50000; i++) {
    if (dp[i])
      continue;
    for (int j = 1; j * j <= i; j++) {
      if (!dp[i])
        dp[i] = 1 + dp[i - j * j];
      else {
        dp[i] = min(dp[i], 1 + dp[i - j * j]);
      }
    }
  }

  cout << dp[n];

  return 0;
}