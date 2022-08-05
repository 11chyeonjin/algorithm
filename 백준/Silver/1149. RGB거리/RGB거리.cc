#include <iostream>
using namespace std;

int user[1000][3];

int main() {
  int n;
  cin >> n;

  int inR, inG, inB;
  for (int i = 0; i < n; i++) {
    cin >> inR >> inG >> inB;
    user[i][0] = inR;
    user[i][1] = inG;
    user[i][2] = inB;
  }

  for (int i = 1; i < n; i++) {
    user[i][0] += min(user[i-1][1], user[i-1][2]);
    user[i][1] += min(user[i-1][0], user[i-1][2]);
    user[i][2] += min(user[i-1][0], user[i-1][1]);
  }

  int min_result = min(user[n-1][0], user[n-1][1]);
  cout << min(min_result, user[n-1][2]);

  return 0;
}