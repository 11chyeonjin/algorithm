#include <iostream>
#include <vector>
using namespace std;

int N;

int binary_search(int target, vector<int>& lis, int top_idx) {
  int left = 0;
  int right = top_idx;

  int mid;
  while(left < right) {
    mid = (left + right) / 2;
    if (lis[mid] > target) {
      right = mid;
    } else if (lis[mid] < target) {
      left = mid + 1;
    } else {
      return -1;
    }
  }

  return left;
}

int lis_func(vector<int>& v, vector<int>& lis_index) {
  vector<int> lis(N);

  lis[0] = v[0]; // 첫 원소 기본 삽입
  lis_index[0] = 0;
  int top_idx = 0;

  for (int i = 1; i < N; i++) {
    // lis 길이를 늘릴 수 있다면, 
    if (v[i] > lis[top_idx]) { 
      lis[++top_idx] = v[i];
      lis_index[i] = top_idx;
    } 
    // 길이를 늘릴 수 없다면, 이진탐색으로 위치를 찾아서 교체
    else {
      int tmp = binary_search(v[i], lis, top_idx);
      if (tmp != -1) {
        lis[tmp] = v[i];
        lis_index[i] = tmp;
      }
    }
  }

  return top_idx;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;

  vector<int> v(N);
  vector<int> lis_index(N);
  
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }

  int lis_len = lis_func(v, lis_index) + 1;

  cout << lis_len << "\n";

  int cur_idx = lis_len - 1;
  int cur_value = 1987654321;

  vector<int> result;
  for (int i = N - 1; i >= 0; i--) {
    if (lis_index[i] == cur_idx && v[i] < cur_value) {
      cur_idx--;
      result.push_back(v[i]);
      cur_value = v[i];
    }
  }

  for (int i = result.size() - 1; i >= 0; i--) {
    cout << result[i] << " ";
  }
  
  return 0;
}