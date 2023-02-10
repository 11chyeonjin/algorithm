#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string S, T;

int main() {
  cin >> S >> T;

  bool direction = true; // 정방향
  
  while(S.size() < T.size()) {
    if (direction) { // 정방향
      if (T[T.size() - 1] == 'A') {
        T.pop_back();
      }
      else {
        T.pop_back();
        direction = !direction;
      }
    }
    else { // 역방향
      if (T[0] == 'A') {
        T = T.substr(1, T.size() - 1);
      }
      else {
        T = T.substr(1, T.size() - 1);
        direction = !direction;
      }
    }
  }

  if (direction) {
    if (S == T)
      cout << 1;
    else 
      cout << 0;
  } else {
    reverse(S.begin(), S.end());
    if (S == T)
      cout << 1;
    else
      cout << 0;
  }

  return 0;
}