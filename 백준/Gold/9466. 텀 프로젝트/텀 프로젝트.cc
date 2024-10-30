#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int T;

int sol(int n, vector<int> &v) {
  vector<int> selected(n + 1, 0); // 0 확인X, 1 팀 구성 가능, -1 팀 구성 불가
  
  for (int i = 1; i <= n; i++) {
    if (selected[i]) {
      continue;
    }
    
    int curStd = i;
    set<int> s;
    bool flag = false;

    while(true) {
      s.insert(curStd); // 현재 방문한 노드를 set에 추가

      if (selected[curStd]) { // 현재 노드가 선정된 노드라면 while문 종료
        break;
      }
      
      int nextStd = v[curStd]; // 다음 노드

      if (!flag) {
        if (s.find(nextStd) != s.end()) {
          selected[curStd] = 1;
          flag = true;
        }
      } else {
        selected[curStd] = 1;
      }

      curStd = nextStd;
    }

    for(auto sValue : s) {
      if (!selected[sValue]) {
        selected[sValue] = -1;
      }
    }
  }

  int rst = 0;
  for (int i = 1; i <= n; i++) {
    if (selected[i] == -1) {
      rst++;
    }
  }

  return rst;
}

int main() {
  // 팀 (사이클)이 만들어지는 순간 그 학생들을 제외.
  // 시행마다 처음으로 재방문된 노드 기준으로 다시 사이클을 탐색하여 selected를 최신화, 시행에서 방문은 했으나 결국 팀 구성에 실패한 노드들은 따로 체크하여 결과에 반영
  // 자기 자신을 선택한 노드에 주의해야함.
  cin >> T;
  int n;

  vector<int> probRst;

  while(T--) {
    cin >> n;
    
    vector<int> v(n + 1, 1); // 1부터 시작
    for (int i = 1; i <= n; i++) {
      cin >> v[i];
    }
    
    probRst.push_back(sol(n, v));
  }

  for (auto rst : probRst) {
    cout << rst << "\n";
  }

  return 0;
}