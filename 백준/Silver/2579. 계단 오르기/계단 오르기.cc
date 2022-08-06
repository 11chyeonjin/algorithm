#include <iostream>
using namespace std;

int stair[302][2];

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n, in;
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    cin >> in;
    stair[i][0] = in;
    stair[i][1] = in;
  }

  // stair[0][0] 만 존재. 그대로 사용
  // stair[1][0] 그대로, stair[1][1] += stair[0][0].

  stair[1][1] += stair[0][0];
  for (int i = 2; i <= n-1; i++) {
    stair[i][0] += max(stair[i - 2][0], stair[i - 2][1]);
    stair[i][1] += stair[i - 1][0];
  }

  cout << max(stair[n-1][0], stair[n-1][1]);
  
  return 0;
}