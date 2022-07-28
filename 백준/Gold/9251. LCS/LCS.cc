#include <iostream>
using namespace std;

int user[1001][1001] = { 0 };

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  string first;
  string second;
  cin >> first >> second;

  int fs = first.size();
  int ss = second.size();
  for (int i = 1; i <= fs; i++) {
    for (int j = 1; j <= ss; j++) {
      if (first[i - 1] == second[j - 1]) {
        user[i][j] = user[i - 1][j - 1] + 1;
      }
      else {
        user[i][j] = max(user[i-1][j], user[i][j-1]);
      }
    }
  }

  cout << user[fs][ss];
  return 0;
}