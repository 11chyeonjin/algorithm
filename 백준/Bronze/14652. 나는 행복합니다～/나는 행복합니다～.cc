#include <iostream>
using namespace std;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  
  int y = K / M;
  int x = K % M;

  cout << y << " " << x;

  return 0;
}