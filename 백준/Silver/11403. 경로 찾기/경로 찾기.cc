#include <iostream>
using namespace std;

int user[100][100];

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n; 
  int in;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> in;
      user[i][j] = in;
    }
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (user[i][k] && user[k][j]) {
          user[i][j] = 1;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << user[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}