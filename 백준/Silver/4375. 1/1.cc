#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> result;

int main() {
  while(true) {
    cin >> n;
    if (cin.eof())
      break;
    int tmp = 1;
    int now = 1;
    while(true) {
      if (tmp % n == 0) {
        result.push_back(now);
        break;
      }
      else {
        tmp = tmp * 10 + 1;
        tmp %= n;
        now++;
      }
    }
  }

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << "\n";
  }

  return 0;
}