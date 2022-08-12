#include <iostream>
using namespace std;

int dp[21][21][21] = { 0 };

int w (int a, int b, int c) {
  if (a <= 0 || b <= 0 || c <= 0)
    return 1;
  else if (a > 20 || b > 20 || c > 20) {
    return w(20, 20, 20);
  }
  else if (a < b && b < c) {
    if (dp[a][b][c])
      return dp[a][b][c];
    else {
      dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
      return dp[a][b][c];
    }
  }
  else {
    if (dp[a][b][c])
      return dp[a][b][c];
    else {
      dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
      return dp[a][b][c];
    } 
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int a, b, c;
  while(1) {
    cin >> a >> b >> c;
    if (a == -1 && b == -1 && c == -1)
      return 0;
    cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
  }

  return 0;
}