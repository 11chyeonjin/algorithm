#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  
  int T;
  char com;
  int k;
  int in;
  priority_queue<int, vector<int>, less<int>> max_q;
  priority_queue<int, vector<int>, greater<int>> min_q;
  map<int,int> m;  
  cin >> T;
  while(T--) {
    cin >> k;

    m.clear();
    while (!max_q.empty())
      max_q.pop();
    while (!min_q.empty())
      min_q.pop();
    
    while (k--) {
      cin >> com >> in;
      if (com == 'I') {
        max_q.push(in);
        min_q.push(in);
        m[in]++;
      }
      else {   // D 일때
        if (in == 1) {
          while (!max_q.empty() && m[max_q.top()] == 0) {
            max_q.pop();
          }
          if (!max_q.empty()) {
            m[max_q.top()]--;
            max_q.pop();
          }
        }
        else {  // -1 일때
          while (!min_q.empty() && m[min_q.top()] == 0) {
            min_q.pop();
          }
          if (!min_q.empty()) {
            m[min_q.top()]--;
            min_q.pop();
          }
        }
      }
    }

    while (!max_q.empty() && m[max_q.top()] == 0) {
      max_q.pop();
    }
    
    while (!min_q.empty() && m[min_q.top()] == 0) {
      min_q.pop();
    }
    
    if (max_q.empty() || min_q.empty())
      cout << "EMPTY\n";
    else {
      cout << max_q.top() << " " << min_q.top() << "\n";
    }
  }
  return 0;
}