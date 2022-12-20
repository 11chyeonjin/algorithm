#include <iostream>
#include <stack>
using namespace std;

int N;

int main() {
  cin >> N;
  string tmp;
  int count = 0;
  for (int i = 0; i < N; i++) {
    stack<char> word;
    cin >> tmp;
    for (int j = 0; j < tmp.size(); j++) {
      if (!word.empty() && (word.top() == tmp[j])) {
        word.pop();
      }
      else {
        word.push(tmp[j]);
      }
    }
    if (word.empty()) {
      count++;
    }
  }
  cout << count;

  return 0;
}