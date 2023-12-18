#include <iostream>
using namespace std;

int arr[1000000];
int lis[1000000];

int func(int target, int lis_idx) {
  // 이진탐색을 이용해서 자리를 return (lis)
  // 같은 값을 찾을 경우 그 자리를. 같은 값이 없을 경우 자기 자리를
  int mid;
  int left = 0;
  int right = lis_idx;

  while (left <= right) {
    mid = (left + right) / 2;

    if (lis[mid] < target) {
      left = mid + 1;
    } else if (lis[mid] > target) {
      right = mid - 1;
    } else
      return mid;
  }
  
  return right + 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  lis[0] = arr[0];
  int lis_idx = 0;

  for (int i = 1; i < n; i++) { // arr 순회
    if (arr[i] > lis[lis_idx]) {
      lis[++lis_idx] = arr[i];
    } else {
      lis[func(arr[i], lis_idx)] = arr[i];
    }
  }

  cout << lis_idx + 1;
  return 0;
}