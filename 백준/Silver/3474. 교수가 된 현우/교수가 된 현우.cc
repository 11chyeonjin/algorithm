#include <iostream>
using namespace std;

int T;
int five[13] = { 0, };

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> T;
  five[0] = 1;
  for (int i = 1; i < 13; i++) {
    five[i] = five[i - 1] * 5;
  }
  int tmp;
  int result;
  while (T--) {
    cin >> tmp;
    result = 0;
    for (int i = 1; i < 13; i++) {
      if (five[i] <= tmp) {
        result += tmp / five[i];
      }
      else
        break;
    }
    cout << result << "\n";
  }

  return 0;
}