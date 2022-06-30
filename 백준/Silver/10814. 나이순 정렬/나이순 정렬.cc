#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, string> p1, pair<int, string> p2) {
  return p1.first < p2.first;
}


int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  vector <pair<int, string>> library;

  int age;
  string name;
  for (int i = 0; i < N; i++) {
    cin >> age;
    cin >> name;
    library.push_back({age, name});
  }

  stable_sort(library.begin(), library.end(), cmp);

  for (int i = 0; i < N; i++) {
    cout << library[i].first << " " << library[i].second << "\n";
  }

  return 0;
}