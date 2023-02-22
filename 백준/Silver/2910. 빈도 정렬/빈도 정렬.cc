#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int N, C;

map<int, int> m;
int user[1000];
map<int, int> seq;

bool comp(int &a, int &b) {
  if (m[a] != m[b])
    return m[a] > m[b];
  else {
    return seq[a] < seq[b];
  }
}

int main() {
  cin >> N >> C;

  int tmp;
  int num = 0;
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    if (m.find(tmp) == m.end()) {
      seq[tmp] = num;
      user[num] = tmp;
      num++;
    }
    m[tmp]++;
  }

  sort(user, user + N, comp);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < m[user[i]]; j++) {
      cout << user[i] << " ";
    }
  }

  return 0;
}