#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  vector<pair<int, int>> v;
  
  int N, x, y;
  cin >> N;

  vector<int> vrank(N, 1);
  
  for (int i = 0; i < N; i++) {
    cin >> x >> y;
    v.push_back({x, y});
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (v[i].first < v[j].first && v[i].second < v[j].second)
        vrank[i]++;
    }
  }

  for (int i = 0; i < N; i++) {
    cout << vrank[i] << " ";
  }

  return 0;
}