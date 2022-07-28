#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  vector<int> result;

  int T, N, M, in;
  cin >> T;
  while(T--) {
    queue<pair<int,int>> user;
    priority_queue<int> pvalue;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
      cin >> in;
      user.push({in, i});
      pvalue.push(in);
    }
    int vcount = 0;
    while(!user.empty()) {
      int value = user.front().first;
      int where = user.front().second;
      user.pop();
      if (pvalue.top() == value) {
        vcount++;
        pvalue.pop();
        if (where == M) {
          result.push_back(vcount);
          break;
        }
      }
      else {
        user.push({value, where});
      }
    }
  }

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << "\n";
  }
  
  return 0;
}