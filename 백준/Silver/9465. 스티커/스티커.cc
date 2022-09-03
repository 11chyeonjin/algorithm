#include <iostream>
using namespace std;

int user[100000][2];

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int T, n, in;
  cin >> T;
  while(T--) {
    cin >> n;
    for (int j = 0; j < 2; j++) {
      for (int i = 0; i < n; i++) {
        cin >> in;
        user[i][j] = in;
      }
    }
    
    user[1][0] += user[0][1];
    user[1][1] += user[0][0];
    for (int i = 2; i < n; i++) {
      for (int j = 0; j < 2; j++) {
        user[i][j] += max(user[i-1][!j], user[i-2][!j]);
      }
    }

    cout << max(user[n-1][0], user[n-1][1]) << "\n";
  }

  return 0;
}