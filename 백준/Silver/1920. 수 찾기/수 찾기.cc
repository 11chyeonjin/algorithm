#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find(vector<int> &lib, int target) {
  int left = 0;
  int right = lib.size() - 1;
  int mid;
  while (right >= left) {
    mid = (right + left) / 2;
    if (lib[mid] == target) {
      return 1;
    }
    else if (lib[mid] > target) {
      right = mid - 1;
    }
    else
      left = mid + 1;
  }
  return 0;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  vector<int> library;
  vector<int> result;
  
  int user_input;
  for (int i = 0; i < N; i++) {
    cin >> user_input;
    library.push_back(user_input);
  }
  sort(library.begin(), library.end());
  
  int M;
  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> user_input;
    result.push_back(find(library, user_input));
  }

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << "\n";
  }

  return 0;
}
  