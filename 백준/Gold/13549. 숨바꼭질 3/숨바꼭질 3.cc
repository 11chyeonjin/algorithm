#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int N, K;

struct comp {
  bool operator()(pair<int,int> p1, pair<int,int> p2) {
    return p1.first > p2.first;
  }
};

int bfs(vector<int>& time_v) { 
  // 찾자마자 즉시 종료하기 위해 pq 사용
  priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq; 
  // pair의 형태는 {cur_time, cur_node}
  pq.push({0, N});
  time_v[N] = 0;

  // 최대 탐색 기준
  int maximum;
  if (N < K) {
    maximum = min(100001, 2 * K + 1);
  } else {
    maximum = N + 1;
  }

  while (!pq.empty()) {
    int cur = pq.top().second;
    int cur_time = pq.top().first;
    pq.pop();

    // +1 로 걸을 경우
    if (0 <= cur + 1  && cur + 1 < maximum) {
      if (time_v[cur + 1] > cur_time + 1) {
        pq.push({cur_time + 1, cur + 1});
        time_v[cur + 1] = cur_time + 1;
      }
    }
    
    // -1 로 걸을 경우
    if (0 <= cur - 1  && cur - 1 < maximum) {
      if (time_v[cur - 1] > cur_time + 1) {
        pq.push({cur_time + 1, cur - 1});
        time_v[cur - 1] = cur_time + 1;
      }
    }

    // 순간 이동의 경우
    while(0 < cur * 2 && cur * 2 < maximum) {
      if (time_v[cur * 2] > cur_time) {
        pq.push({cur_time, cur * 2});
        time_v[cur * 2] = cur_time;
      } 
      // else {
      //   break;
      // }
      cur *= 2; // 논리상 없어도 될 지도..? 어떻게든 한번씩 다 순간이동했을 것
    }
  }

  return time_v[K];
}

int main() {
  cin >> N >> K;

  vector<int> time_v(100001, INF);

  cout << bfs(time_v);

  return 0;
}