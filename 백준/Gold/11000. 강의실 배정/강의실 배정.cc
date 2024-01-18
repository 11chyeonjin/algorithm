#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;

struct comp {
  bool operator()(pair<int,int> p1, pair<int,int> p2) {
    return p1.first > p2.first;
  }
};

int main() {
  cin >> N;

  priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq; // first 오름차순
  
  int s, e;
  for (int i = 0; i < N; i++) {
    cin >> s >> e;
    pq.push({s, e});
  }

  priority_queue<int, vector<int>, greater<>> ans;

  while(!pq.empty()) {
    int lec_start = pq.top().first;
    int lec_end = pq.top().second;
    pq.pop();

    // cout << lec_start << " " << lec_end << " ";

    if (!ans.size()) {
      ans.push(lec_end);
      // cout << "강의실 추가\n";
      continue;
    }

    if (ans.top() <= lec_start) {
      // cout << ans.top() << " 에 가능 " << lec_end << "\n";
      ans.pop();
      ans.push(lec_end);
    } else {
      // cout << "강의실 추가\n";
      ans.push(lec_end);
    }
  }

  cout << ans.size();

  return 0;
}