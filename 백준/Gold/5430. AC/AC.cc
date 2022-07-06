#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <deque>
#include <vector>
using namespace std;

void R(deque<int> &v, int &state) {
  if (!state)
    state = 1;
  else
    state = 0;
}

bool D(deque<int> &v, int &error, int &state) {
  if (v.size() == 0) {
    error = 1;
    return true;
  }
  if (state == 0) {
    v.pop_front();
  } 
  else {
    v.pop_back();
  }
  return false;
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  deque<int> tmp;  // 임시 덱
  vector<string> result; // 결과     

  int T;
  cin >> T;

  string p;    // 명령 입력
  int size;    // 입력 배열에 포함된 정수의 개수
  string list; // 입력 배열
  int error;   // 에러 여부
  for (int i = 0; i < T; i++) {
    error = 0;
    tmp.clear();
    cin >> p;
    cin >> size;
    cin >> list;

    int tmp_state = 0; // 정방향 0, 역방향 1

    for (int j = 0; j < list.size(); j++) {
      if (!isdigit(list[j]))
        list[j] = ' ';
    }

    int tmp_int;
    stringstream ss;
    ss.str(list);

    for (int j = 0; j < size; j++) {
      ss >> tmp_int;
      tmp.push_back(tmp_int);
    }

    for (int j = 0; j < p.size(); j++) {
      if (p[j] == 'R') {
        R(tmp, tmp_state);
      } else if (p[j] == 'D') {
        if (D(tmp, error, tmp_state))
          break;
      }
    }

    string tmp_result = "[";
    if (error) {
      result.push_back("error");
    } else {
      if (!tmp_state) {
        if (!tmp.size()) {
          tmp_result.append("]");
        }
        for (int j = 0; j < tmp.size(); j++) {
          tmp_result.append(to_string(tmp[j]));
          if (j == (tmp.size() - 1)) {
            tmp_result.append("]");
          } else {
            tmp_result.append(",");
          }
        }
        result.push_back(tmp_result);
      } else {
        if (!tmp.size()) {
          tmp_result.append("]");
        }
        for (int j = tmp.size() - 1; j >= 0; j--) {
          tmp_result.append(to_string(tmp[j]));
          if (j == 0) {
            tmp_result.append("]");
          } else {
            tmp_result.append(",");
          }
        }
        result.push_back(tmp_result);
      }
    }
  }
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << "\n";
  }
  return 0;
}