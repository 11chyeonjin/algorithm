#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  int R;
  string S;
  vector<vector<char>> newS(T);
  for (int i = 0; i < T; i++) {
    cin >> R;
    cin >> S;
    for (int j = 0; j < S.size(); j++) {
      for (int k = 0; k < R; k++) {
        newS[i].push_back(S[j]);
      }
    }
  }
  for (int i = 0; i < T; i++) {
    for (int j = 0; j < newS[i].size(); j++) {
      cout << newS[i][j];
    }
    cout << "\n";
  }

  return 0;
}