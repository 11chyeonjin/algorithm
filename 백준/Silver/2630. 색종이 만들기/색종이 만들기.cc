#include <iostream>
using namespace std;

int blue_result = 0;
int white_result = 0;
bool user[128][128];

bool check(int a, int au, int b, int bu) {
  for (int i = a; i <= au; i++) {
    for (int j = b; j <= bu; j++) {
      if (!user[i][j])
        return false;
    }
  }
  return true;
}

bool wcheck(int a, int au, int b, int bu) {
  for (int i = a; i <= au; i++) {
    for (int j = b; j <= bu; j++) {
      if (user[i][j])
        return false;
    }
  }
  return true;
}

void func(int a, int au, int b, int bu) {
  int atmp, btmp;
  if (!check(a, au, b, bu)) {
    if ((au - a) != 0) {
      atmp = (a + au) / 2;
      btmp = (b + bu) / 2;
      func(a, atmp, b, btmp);
      func(atmp + 1, au, b, btmp);
      func(a, atmp, btmp + 1, bu);
      func(atmp + 1, au, btmp + 1, bu);
    }
  }
  else {
      blue_result++;
  }
}

void wfunc(int a, int au, int b, int bu) {
  int atmp, btmp;
  if (!wcheck(a, au, b, bu)) {
    if ((au - a) != 0) {
      atmp = (a + au) / 2;
      btmp = (b + bu) / 2;
      wfunc(a, atmp, b, btmp);
      wfunc(atmp + 1, au, b, btmp);
      wfunc(a, atmp, btmp + 1, bu);
      wfunc(atmp + 1, au, btmp + 1, bu);
    }
  }
  else {
    white_result++;
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N, in;
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> in;
      user[i][j] = in;
    }
  }

  func(0, N - 1, 0, N - 1);
  wfunc(0, N - 1, 0, N - 1);
  
  cout << white_result << "\n" << blue_result;
  return 0;
}