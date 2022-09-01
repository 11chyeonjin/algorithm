#include <iostream>
using namespace std;

int N;

int max_dp[3] = { 0 };
int min_dp[3] = { 0 };

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;
  
  int in0, in1, in2;
  int tmp0, tmp1, tmp2;
  for (int i = 0; i < N; i++) {
    cin >> in0 >> in1 >> in2;
    tmp0 = max_dp[0];
    tmp1 = max_dp[1];
    tmp2 = max_dp[2];

    max_dp[0] = in0 + max(tmp0, tmp1);
    max_dp[1] = in1 + max(tmp0, max(tmp1, tmp2));
    max_dp[2] = in2 + max(tmp1, tmp2);

    tmp0 = min_dp[0];
    tmp1 = min_dp[1];
    tmp2 = min_dp[2];

    min_dp[0] = in0 + min(tmp0, tmp1);
    min_dp[1] = in1 + min(tmp0, min(tmp1, tmp2));
    min_dp[2] = in2 + min(tmp1, tmp2);
  }

  cout << max(max_dp[0], max(max_dp[1], max_dp[2])) << " ";
  cout << min(min_dp[0], min(min_dp[1], min_dp[2]));

  return 0;
}