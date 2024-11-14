#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool comp(pair<int,int> p1, pair<int,int> p2) { // first 원소(무게) 기준으로 오름차순
  return p1.first < p2.first;
}

struct compare {
  bool operator()(pair<int,int> p1, pair<int,int> p2) { // second 원소(가격) 기준으로 내림차순
    return p1.second < p2.second;
  }
};

int main() {
  int N, K;
  cin >> N >> K;

  vector<pair<int,int>> jewelry; // {무게, 가격}
  
  int M, V;
  for (int i = 0; i < N; i++) {
    cin >> M >> V;
    jewelry.push_back({M, V});
  }

  vector<int> bag;
  int C;
  for (int i = 0; i < K; i++) {
    cin >> C;
    bag.push_back(C);
  }

  sort(bag.begin(), bag.end(), less<>());
  sort(jewelry.begin(), jewelry.end(), comp); // first 원소(무게) 기준으로 오름차순

  priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
  
  long long rst = 0;
  int jewelryIdx = 0;

  for (int i = 0; i < bag.size(); i++) {
    int curBag = bag[i];
    
    while(jewelryIdx < jewelry.size()) {
      pair<int,int> curJewelry = jewelry[jewelryIdx]; 
      if (curJewelry.first > curBag) { // 확인중인 보석이 지금 가방의 무게를 넘는다면
        break;
      }
      jewelryIdx++;
      pq.push(curJewelry);
    }
    
    if (pq.empty()) {
      continue;
    } else {
      // cout << curBag << " 가방에 " << pq.top().second << " 무게를 가진 보석은 삽입\n";
      rst += pq.top().second;
      pq.pop();
    }
  }

  cout << rst;
  
  return 0;
}