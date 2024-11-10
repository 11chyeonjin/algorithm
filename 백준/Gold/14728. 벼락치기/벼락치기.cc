#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, T;
  cin >> N >> T;
  
  int K, S;

  vector<pair<int,int>> v; // {공부시간, 배점}
  
  for (int i = 0; i < N; i++) {
    cin >> K >> S;
    v.push_back({K, S});
  }

  vector<vector<int>> dp(v.size(), vector<int> (T + 1, 0));

  for (int i = 0; i < v.size(); i++) {
    for (int j = 1; j <= T; j++) {
      if (i == 0) {
        if (j >= v[i].first) {
          dp[i][j] = v[i].second;
        }
        continue;
      }
      if (j >= v[i].first) {
        dp[i][j] = max(dp[i - 1][j] , dp[i - 1][j - v[i].first] + v[i].second);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  cout << dp[v.size() - 1][T];

  return 0;
}