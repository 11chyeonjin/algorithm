#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int user[26][2]; // [][0] 왼쪽, [][1] 오른쪽 child

void pre(int num) {
  if (num != -1) {
    cout << (char)(num + 'A');
    pre(user[num][0]);
    pre(user[num][1]);
  }
}

void in(int num) {
  if (num != -1) {
    in(user[num][0]);
    cout << (char)(num + 'A');
    in(user[num][1]);
  }
}

void post(int num) {
  if (num != -1) {
    post(user[num][0]);
    post(user[num][1]);
    cout << (char)(num + 'A');
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  char what, c0, c1;
  cin >> N;

  fill(&user[0][0], &user[25][2], -1);
  for (int i = 0; i < N; i++) {
    cin >> what >> c0 >> c1;
    what -= 'A';
    if (c0 != '.') {
      user[what][0] = c0 - 'A';
    }
    if (c1 != '.') {
      user[what][1] = c1 - 'A';
    }
  }

  pre(0);
  cout << "\n";
  in(0);
  cout << "\n";
  post(0);

  return 0;
}