#include <iostream>
using namespace std;

int user[5001][5001] = { 0 };

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  int a, b;
  while(M--) {
    cin >> a >> b;
    user[a][b] = 1;
    user[b][a] = 1;
  }
  
  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (i == j)
          continue;
        if (user[i][k] && user[k][j]) {
          if (!user[i][j]) {    // 0이라면, 친구 여부 확인을 못했다면
            user[i][j] = user[i][k] + user[k][j];
          }
          else {              // 이미 친구 사이인 것을 확인했다면, 최단 경로인지 확인
            user[i][j] = min(user[i][j], user[i][k] + user[k][j]); 
          }
        }
      }
    }
  }

  // cout << "===========\n";  // 확인용 코드
  // for (int i = 1; i <= N; i++) {   
  //   for (int j = 1; j <= N; j++) {
  //     cout << user[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "===========\n"; 
  
  int who;
  int sum = 0;
  int min = 1000000;
  for (int i = 1; i <= N; i++) {
    sum = 0;
    for (int j = 1; j <= N; j++) {
      sum += user[i][j];
    }
    if (sum < min) {
      who = i;
      min = sum;
    }
  }

  cout << who;

  return 0;
}