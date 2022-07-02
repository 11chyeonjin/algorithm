#include <iostream>
#include <vector>
using namespace std;

void add(vector<int> &v, int num) {
  if (v[num] == 0)
    v[num] = 1;
}

void remove(vector<int> &v, int num) {
  if (v[num] == 1)
    v[num] = 0;
}

int check(vector<int> &v, int num) {
  if (v[num] == 1)
    return 1;
  else
    return 0;
}

void toggle(vector<int> &v, int num) {
  if (v[num] == 1)
    v[num] = 0;
  else
    v[num] = 1;
}

void all(vector<int> &v) {
  for (int i = 1; i <= 20; i++) {
    v[i] = 1;
  }
}

void empty(vector<int> &v) {
  for (int i = 1; i <= 20; i++) {
    v[i] = 0;
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  vector<int> S(21, 0);
  
  int M;
  cin >> M;
  string user;
  int in;
  for (int i = 0; i < M; i++) {
    cin >> user;
    if (user == "add") {
      cin >> in;
      add(S, in);
    }
    else if (user == "remove") {
      cin >> in;
      remove(S, in);
    }
    else if (user == "check") {
      cin >> in;
      cout << check(S, in) << "\n";
    }
    else if (user == "toggle") {
      cin >> in;
      toggle(S, in);
    }
    else if (user == "all") {
      all(S);
    }
    else if (user == "empty") {
      empty(S);
    }
  }

  return 0;
}