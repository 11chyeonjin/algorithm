#include <iostream>
using namespace std;

int N, M;

int user[1025][1025] = { 0 };

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int in;
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    int tmp = 0;
    for (int j = 1; j <= N; j++) {
      cin >> in;
      if (i == 1) {
        if (j == 1)
          user[i][j] = in;
        else {
          user[i][j] = user[i][j - 1] + in;
        }
      }
      else {
        tmp += in;
        user[i][j] = tmp + user[i - 1][j]; 
      }
    }
  }

  int a, aa, b, bb;
  while(M--) {
    cin >> a >> b >> aa >> bb;
    int result = user[aa][bb] - user[aa][b - 1] - user[a - 1][bb] + user[a - 1][b - 1];
    cout << result << "\n";
  }

  return 0;
}