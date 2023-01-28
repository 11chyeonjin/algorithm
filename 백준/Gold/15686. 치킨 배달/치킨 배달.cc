#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N, M;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;

vector<vector<int>> selectList;

void combi(int start, vector<int> v) { // 조합
  if (v.size() == M) {
    selectList.push_back(v);
    return;
  }

  for (int i = start + 1; i < chicken.size(); i++) {
    v.push_back(i);
    combi(i, v);
    v.pop_back();
  }
}

int main() {
  cin >> N >> M;
  int tmp;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> tmp;
      if (tmp == 1) {
        home.push_back({i, j});
      }
      else if (tmp == 2) {
        chicken.push_back({i, j});
      }
    }
  }

  vector<int> v;
  combi(-1, v);

  // for (vector<int> cList : selectList) {
  //   for (int i = 0; i < cList.size(); i++) {
  //     cout << cList[i] << " ";
  //   }
  
  //   cout << "\n";
  // }

  int distSum, _dist, _min;

  int result = 987654321;
  
  for (vector<int> cList : selectList) { // 치킨집 선택 반복
    distSum = 0; // 해당 시행의 치킨거리
    for (pair<int , int> h : home) { // 집 반복
      _min = 987654321;
      for (int c : cList) { // 집별 선택된 치킨집 반복
        _dist = abs(h.first - chicken[c].first) + abs(h.second - chicken[c].second);
        _min = min(_dist, _min);
      }
      distSum += _min;
    }
    result = min(result, distSum); // 최소 치킨거리를 구함
  }

  cout << result;

  return 0;
}