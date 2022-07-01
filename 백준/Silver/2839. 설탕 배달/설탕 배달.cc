#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> sugar(5001);
  sugar[3] = sugar[5] = 1;

  for (int i = 6; i <= N; i++) {
    if (sugar[i-3]) {
      sugar[i] = sugar[i-3] + 1;
    }
    if (sugar[i-5]) {
      if (sugar[i])
        sugar[i] = min(sugar[i], sugar[i-5] + 1);
      else
        sugar[i] = sugar[i-5] + 1;
    }
  }
  if (sugar[N] == 0)
    cout << "-1";
  else
    cout << sugar[N];

  return 0;
}