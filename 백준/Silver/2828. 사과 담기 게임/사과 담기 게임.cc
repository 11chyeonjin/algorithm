#include <iostream>
#include <vector>
using namespace std;

int N, M, J;

int result = 0;

int main() {
  cin >> N >> M >> J;
  int tmp;
  int front = 1;
  int back = M;
  for (int i = 0; i < J; i++) {
    cin >> tmp;
    if (tmp < front) {
      result += front - tmp;
      back = back - front + tmp;
      front = tmp;
    }
    else if (tmp > back) {
      result += tmp - back;
      front = front + tmp - back;
      back = tmp;
    }
  }

  cout << result;
  return 0;
}