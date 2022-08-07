#include <iostream>
using namespace std;

int user[500][500];

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n, in;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cin >> in;
      user[i][j] = in;
    }
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == i)
        user[i][j] += user[i-1][j-1];
      else if (j == 0)
        user[i][j] += user[i - 1][j];
      else
        user[i][j] += max(user[i - 1][j - 1], user[i - 1][j]);
    }
  }

  int max = -1;
  for (int i = 0; i < n; i++) {
    if (user[n - 1][i] > max)
      max = user[n - 1][i];
  }

  cout << max;

  return 0;
}