#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  vector<int> user(1000001);

  int n;
  cin >> n;

  user[1] = 0;
  user[2] = user[3] = 1;
  
  for (int i = 4; i <= n; i++) {
    user[i] = user[i - 1] + 1;
    if (i % 3 == 0) {
      user[i] = min(user[i], user[i / 3] + 1);
    }
    if (i % 2 == 0) {
      user[i] = min(user[i], user[i / 2] + 1);
    }
  }

  cout << user[n];

  return 0;
}