#include <iostream>
using namespace std;

int temp[100001]; // 앞선 온도들의 누적합

int main() {
  int N, K;
  cin >> N >> K;

  int tmp;
  temp[0] = 0; // 0 번째는 0으로 저장. 연산시 용이성
  for (int i = 1; i <= N; i++) {
    cin >> tmp;
    temp[i] = temp[i - 1] + tmp;
  }

  int maxT = -9999;
  for (int i = K; i <= N; i++) {
    maxT = max(maxT, temp[i] - temp[i - K]);
  }

  cout << maxT;
  return 0;
}