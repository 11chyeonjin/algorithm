#include <iostream>
#include <algorithm>
using namespace std;

int N, M, tmp; 
int arr[15000];

int result = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M; // N은 재료의 개수, M은 타겟값.
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    arr[i] = tmp;
  }

  sort(arr , arr + N);

  int front = 0;
  int back = N - 1;

  int count = 0;

  while(front < back) {
    if (arr[front] + arr[back] == M) {
      count++;
      front++;
      back--;
    }
    else if (arr[front] + arr[back] > M) {
      back--;
    }
    else { // 타겟값보다 계산값이 작을 때.
      front++;
    }
  }

  cout << count;
  return 0;
}