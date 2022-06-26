#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> &p1, pair<int, int> &p2) {
  if (p1.second == p2.second) {
    return p1.first < p2.first;
  }
  else
    return p1.second < p2.second;
}

int main() {
  int N;
  cin >> N;

  vector<pair<int, int>> user;
  int x, y;
  for (int i = 0; i < N; i++) {
    cin >> x;
    cin >> y;
    user.push_back({x, y});
  }
  sort(user.begin(), user.end(), comp);

  for (int i = 0; i < N; i++) {
    cout << user[i].first << " " << user[i].second << "\n";
  }
  return 0;
}