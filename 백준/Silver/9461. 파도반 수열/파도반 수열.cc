#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  vector<long> v(101);
  v[1] = 1;
  v[2] = 1;
  v[3] = 1;

  for (int i = 4; i <= 100; i++) {
    v[i] = v[i - 2] + v[i - 3];
  }
  
  int T;
  cin >> T;
  int in;

  for (int i = 0; i < T; i++) {
    cin >> in;
    cout << v[in] << "\n";
  }

  return 0;
}