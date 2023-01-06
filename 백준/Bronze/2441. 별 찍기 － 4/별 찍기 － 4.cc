#include <iostream>
using namespace std;

int N;

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      cout << " ";
    }
    for (int j = N - i; j > 0; j--) {
      cout << "*";
    }
    cout << "\n";
  }

  return 0;
}