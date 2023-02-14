#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  string tmp;
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    for (int j = 0; j < tmp.size(); j++) {
      if ('A' <= tmp[j] && tmp[j] <= 'Z') {
        tmp[j] = tmp[j] - 'A' + 'a';
      }
    }
    cout << tmp << "\n";
  }

  return 0;
}