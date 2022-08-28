#include <iostream>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N, M;
  char s;
  
  cin >> N >> M;

  int result= 0;
  int now = 0;
  bool flag = false;
  bool start = false;
  for (int i = 0; i < M; i++) {
    cin >> s;
    if (s == 'O') {
      if (start) {
        if (flag)  { // O O 
          flag = false;
          start = false;
          now = 0;
        }
        else { // flag == false, O
          flag = true;
        }
      }
      else { // start == false, 0
        now = 0;
      }
    }
    else { // s == 'I'
      if (start) {
        if (flag) { // O I
          flag = false;
          now++;
          if (now >= N)
            result++;
        }
        else { // flag == false, I
          now = 0;
        }
      }
      else { // start == false
        start = true;
        now = 0;
      }
    }
  }

  cout << result;

  return 0;
}