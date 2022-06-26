#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> &v1, pair<int, int> &v2) {
  if (v1.second == v2.second)
    return v1.first < v2.first;
  else
    return v1.second < v2.second;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N = 0;
  cin >> N;

  vector<pair<int, int>> user;

  int fi, si;
  for (int i = 0; i < N; i++) {
    cin >> fi;
    cin >> si;
    user.push_back({fi, si});
  }
  
  sort(user.begin(), user.end(), cmp); 
  
  int count = 1;
  int now = user[0].second;
  for (int i = 1; i < N; i++) {
    if (user[i].first >= now) {
      count++;
      now = user[i].second;
    }
  }
  cout << count;
  return 0;
}