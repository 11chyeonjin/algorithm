#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int max_idx = 0;

bool first_greater(pair<int, int> p1, pair<int, int> p2) {
  return p1.first < p2.first;
}

int binary_search_func(vector<pair<int,int>>& lis_v, int target, int top_idx) {
  int left_idx = 0;
  int right_idx = top_idx;

  int mid;
  
  while(left_idx < right_idx) {
    mid = (left_idx + right_idx) / 2;
    
    if (lis_v[mid].second > target) {
      right_idx = mid;
    } else if (lis_v[mid].second < target) {
      left_idx = mid + 1;
    } else {
      return -1;
    }
  }

  return left_idx;
}

void main_func(vector<pair<int,int>>& v, vector<int>& lis_index) {
  vector<pair<int,int>> lis_v(N);
  lis_v[0] = {v[0].first, v[0].second};
  lis_index[0] = 0;
  
  int top_idx = 0;

  for (int i = 1; i < v.size(); i++) {
    if (lis_v[top_idx].second < v[i].second) { 
      // 만약, 길이를 늘릴 수 있다면
      
      lis_v[++top_idx] = {v[i].first, v[i].second};
      lis_index[i] = top_idx;
    } else if (lis_v[top_idx].second > v[i].second) { 
      // 길이를 늘릴 수 없다면,
      
      int tmp = binary_search_func(lis_v, v[i].second, top_idx);
      if (tmp != -1) {
        lis_v[tmp] = {v[i].first, v[i].second};
        lis_index[i] = tmp;
      }
    }

    max_idx = max(max_idx, top_idx); // top_idx는 인덱스이므로 최장수열의 길이보다 1 작음!
  }
  max_idx += 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  /*
    1. LIS로 접근
  */
  cin >> N;

  vector<pair<int,int>> v;
  vector<int> lis_index(N);

  int a, b;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    v.push_back({a, b});
  }

  sort(v.begin(), v.end(), first_greater);

  main_func(v, lis_index);

  cout << N - max_idx << "\n";

  int now_idx = max_idx - 1;
  int now_value = 500001;
  for (int i = N - 1; i >= 0; i--) {
    if (lis_index[i] == now_idx && v[i].first < now_value) {
      lis_index[i] = -1;
      now_idx--;
      now_value = v[i].first;
    }
  }

  for (int i = 0; i < N; i++) {
    if (lis_index[i] != -1) {
      cout << v[i].first << "\n";
    }
  }

  return 0;
}