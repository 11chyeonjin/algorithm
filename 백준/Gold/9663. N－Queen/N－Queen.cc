#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int N;

int result = 0;

vector<int> user(15);

void dfs_chess(int a) {
  // 현재 a의 값을 인수로, 재귀적으로 호출하여 연산
  if (a == N) {
    result++;
  } 
  else {
    for (int b = 0; b < N; b++) { // a, b
      bool flag = true;
      for (int i = 0; i < a; i++) {
        if (i - user[i] == a - b || i + user[i] == a + b || user[i] == b) {
          flag = false;
          break;
        }
      }
      if (flag) { // 퀸이 서로 공격하지 못하는게 확인된다면,
        user[a] = b;
        dfs_chess(a + 1);
      }
    }
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;

  dfs_chess(0);
  cout << result;

  return 0;
}