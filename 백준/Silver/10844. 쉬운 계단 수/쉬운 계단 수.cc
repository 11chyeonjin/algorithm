#include <iostream>
using namespace std;

int N;
long long sol[101][10]; // [자릿수][1의 자리 정수]

int main() {
  cin >> N;

  sol[1][0] = 0;
  for (int i = 1; i <= 9; i++) {
    sol[1][i] = 1;
  }

  for (int i = 2; i <= N; i++) {
    sol[i][0] = sol[i - 1][1] % (long long)1000000000;
    for (int j = 1; j <= 8; j++) {
      sol[i][j] = (sol[i - 1][j + 1] + sol[i - 1][j - 1]) % (long long)1000000000;
    }
    sol[i][9] = sol[i - 1][8] % (long long)1000000000;
  }

  long long result = 0;
  for (int i = 0; i <= 9; i++) {
    result += sol[N][i];
    result %= (long long)1000000000;
  }

  cout << result;

  return 0;
}