#include <iostream>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int result[1001] = { 0 };

  result[1] = 1;
  result[2] = 3;

  int n;
  cin >> n;
  
  for (int i = 3; i <= n; i++) {
    result[i] = (result[i - 1] + (result[i - 2] * 2) % 10007) % 10007;
  }
  
  cout << result[n];
  return 0;
}