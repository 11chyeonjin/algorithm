#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  vector<int> remote(10);
  int nobutton;
  for (int i = 0; i < 10; i++) {
    remote[i] = i;
  }
  for (int i = 0; i < M; i++) {
    cin >> nobutton;
    for (int j = 0; j < remote.size(); j++) {
      if (remote[j] == nobutton) {
        remote.erase(remote.begin() + j);
      }
    }
  }
  
  int result = abs(N - 100);
  int tmp = 0;

  if (remote.size()) {
    for (int a = 0; a < remote.size(); a++) {
      for (int b = 0; b < remote.size(); b++) {
        for (int c = 0; c < remote.size(); c++) {
          for (int d = 0; d < remote.size(); d++) {
            for (int e = 0; e < remote.size(); e++) {
              for (int f = 0; f < remote.size(); f++) {
                tmp =  remote[a] * 100000 +  remote[b] * 10000 + remote[c] * 1000 + remote[d] * + 100 + remote[e] * 10 + remote[f];
                //cout << tmp << "\n"; // 삭제
                if (abs(N - tmp) + 6 < result)
                  result = abs(N - tmp) + 6;
                if (f == 0) {
                  tmp = remote[a] * 10000 + remote[b] * 1000 + remote[c] * 100 + remote[d] * 10 + remote[e];
                  //cout << tmp << "\n"; // 삭제
                  if (abs(N - tmp) + 5 < result)
                    result = abs(N - tmp) + 5;
                }
              }
              if (e == 0) {
                tmp = remote[a] * 1000 + remote[b] * 100 + remote[c] * 10 + remote[d];
                //cout << tmp << "\n"; // 삭제
                if (abs(N - tmp) + 4 < result)
                  result = abs(N - tmp) + 4;
              }
            }
            if (d == 0) {
              tmp = remote[a] * 100 + remote[b] * 10 + remote[c];
              //cout << tmp << "\n"; // 삭제
              if (abs(N - tmp) + 3 < result)
                result = abs(N - tmp) + 3;
            }
          }
          if (c == 0) {
            tmp = remote[a] * 10 +  remote[b];
            //cout << tmp << "\n"; // 삭제
            if (abs(N - tmp) + 2 < result)
              result = abs(N - tmp) + 2;
          }
        }
        if (b == 0) {
          tmp = remote[a];
          //cout << tmp << "\n"; // 삭제
          if (abs(N - tmp) + 1 < result)
            result = abs(N - tmp) + 1;
        }
      }  
    }
  }
  cout << result;
  return 0;
}