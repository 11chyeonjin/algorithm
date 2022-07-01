#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n, m, b;
  cin >> n >> m >> b;

  int in;
  int sum = 0;
  vector<vector<int>> minecraft(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> in;
      minecraft[i][j] = in;
      sum += in;
    }
  }

  int minus, plus;
  int min_time = 1999999999;
  int result_h = -1;
  for (int h = 0; h <= 256; h++) {
    minus = 0;
    plus = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (minecraft[i][j] > h) {
          minus += minecraft[i][j] - h;
        }
        else if (minecraft[i][j] < h) {
          plus += h - minecraft[i][j];
        }
      }
    }
    if (minus + b >= plus) {
      if (min_time >= ((minus * 2) + plus)) {
        min_time = ((minus * 2) + plus);
        if (result_h < h) {
          result_h = h;
        }
      }     
    }
  }
  cout << min_time << " " << result_h;

  return 0;
}
  