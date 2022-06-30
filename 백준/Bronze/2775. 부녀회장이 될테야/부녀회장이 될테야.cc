#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int user[15][15] = {0};
  vector<int> result;
  int T;
  cin >> T;

  for (int i = 1; i < 15; i++) {
    user[0][i] = i;
  }
  int sum;
  for (int i = 1; i < 15; i++) {
    sum = 0;
    for (int j = 1; j < 15; j++) {
      sum += user[i - 1][j];
      user[i][j] = sum;
    }
  }
  int k, n;
  for (int i = 0; i < T; i++) {
    cin >> k;
    cin >> n;
    result.push_back(user[k][n]);
  }

  for (int i = 0; i < T; i++) {
    cout << result[i] << "\n";
  }

  return 0;
}