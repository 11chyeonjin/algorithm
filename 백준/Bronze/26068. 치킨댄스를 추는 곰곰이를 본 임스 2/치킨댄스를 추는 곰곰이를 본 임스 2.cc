#include <iostream>
using namespace std;

int N;

int main() {
  cin >> N;
  char tmp;
  int targetTmp;
  int result = 0;
  for (int i = 0; i < N; i++) {
    cin >> tmp >> tmp;
    cin >> targetTmp;
    if (targetTmp <= 90)
      result++;
  }

  cout << result;

  return 0;
}