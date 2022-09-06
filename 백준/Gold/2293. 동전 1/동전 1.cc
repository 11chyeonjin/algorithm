#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;

int dp[10000] = { 0 };

bool compare(int a, int b) {
  return a < b;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n >> k;

  vector<int> coin;
  
  int in;
  for (int i = 0; i < n; i++) {
    cin >> in;
    coin.push_back(in);
  }

  sort(coin.begin(), coin.end(), compare);
  
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      if (j >= coin[i]) {
        dp[j] += dp[j - coin[i]];
      }
    }
  }
  
  cout << dp[k];

  return 0;
}