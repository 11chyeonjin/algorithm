#include <iostream>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int A, B, C;
  cin >> A >> B >> C;

  int hour = C / 60;
  int min = C % 60;

  A += hour;
  B += min;

  if (B >= 60) {
    A++;
    B -= 60;
  }
    
  if (A >= 24)
    A -= 24;

  cout << A << " " << B;

  return 0;
}