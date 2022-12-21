#include <iostream>
using namespace std;

int l, p, v;

int main() {
  int count = 0;
  while(1) {
    count++;
    cin >> l >> p >> v;
    if (!(l * p * v)) {
      break;
    }
    cout << "Case " << count << ": " << (v / p) * l + min(v % p, l) << "\n";
  }

  return 0;
}