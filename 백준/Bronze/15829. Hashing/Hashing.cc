#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int L;
  cin >> L;

  string user;
  cin >> user;

  long long pow = 1;
  long long sum = 0;
  for (int i = 0; i < L; i++) {
    sum += (long long)(((int)user[i] - 96) * pow) % 1234567891;
    pow = (pow * 31) % 1234567891;
  }

  cout << sum % 1234567891;

  return 0;
}