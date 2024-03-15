#include <iostream>
#include <vector>
using namespace std;

int N;
int result = -1;

vector<vector<int>> down_case(vector<vector<int>> v) {
  // 하
  for (int b = 0; b < N; b++){
    int limit = N; // 비정상적으로 합쳐지는걸 방지하기 위해 설정
    for (int a = N - 2; a >= 0; a--) { // 맨 아래칸 제외
      int next_a = a;
      bool flag = false;
      while(++next_a < N) {
        if (v[next_a][b] == 0) {
          // 0 이라면
          continue;
        } else if (next_a >= limit || v[next_a][b] != v[a][b]) {
          // 합쳐질 수 없어서, 다른 블록에 근접하게 쌓이는 경우
          int tmp = v[a][b];
          v[a][b] = 0;
          v[next_a - 1][b] = tmp;
          flag = true;
          break;
        } else {
          // 합칠 수 있다면, 기존 블록을 합친다
          v[a][b] = 0;
          v[next_a][b] *= 2;
          limit = next_a;
          flag = true;
          break;
        }
      }

      if (!flag) {
        // 끝내 합쳐지거나 쌓이지 않아 가장자리로 쌓이는 경우
        v[N - 1][b] = v[a][b];
        v[a][b] = 0;
      }
    }
  }

  return v;
}

vector<vector<int>> up_case(vector<vector<int>> v) {
  // 상
  for (int b = 0; b < N; b++) {
    int limit = -1;
    for (int a = 1; a < N; a++) { // 맨 윗칸 제외
      int next_a = a;
      bool flag = false;
      while(--next_a >= 0) {
        if (v[next_a][b] == 0) {
          // 0 이라면
          continue;
        } else if (next_a <= limit || v[next_a][b] != v[a][b]) {
          // 합쳐질 수 없어, 다른 블록에 근접하게 쌓이는 경우
          int tmp = v[a][b];
          v[a][b] = 0;
          v[next_a + 1][b] = tmp;
          flag = true;
          break;
        } else {
          // 합칠 수 있다면, 기존 블록을 합친다
          v[a][b] = 0;
          v[next_a][b] *= 2;
          limit = next_a;
          flag = true;
          break;
        }
      }

      if (!flag) {
        // 끝내 합쳐지거나 쌓이지 않아 가장자리로 쌓이는 경우
        v[0][b] = v[a][b];
        v[a][b] = 0;
      }
    }
  }

  return v;
}

vector<vector<int>> right_case(vector<vector<int>> v) {
  // 우
  for (int a = 0; a < N; a++) {
    int limit = N;
    for (int b = N - 2; b >= 0; b--) { // 맨 오른쪽칸 제외
      int next_b = b;
      bool flag = false;
      while(++next_b < N) {
        if (v[a][next_b] == 0) {
          // 0 이라면
          continue;
        } else if (next_b >= limit || v[a][next_b] != v[a][b]) {
          // 합쳐질 수 없어, 다른 블록에 근접하게 쌓이는 경우
          int tmp = v[a][b];
          v[a][b] = 0;
          v[a][next_b - 1] = tmp;
          flag = true;
          break;
        } else {
          // 합칠 수 있다면, 기존 블록을 합친다
          v[a][b] = 0;
          v[a][next_b] *= 2;
          limit = next_b;
          flag = true;
          break;
        } 
      }

      if (!flag) {
        // 끝내 합쳐지거나 쌓이지 않아 가장자리로 쌓이는 경우
        v[a][N - 1] = v[a][b];
        v[a][b] = 0;
      }
    }
  }

  return v;
}

vector<vector<int>> left_case(vector<vector<int>> v) {
  // 좌
  for (int a = 0; a < N; a++) {
    int limit = -1;
    for (int b = 1; b < N; b++) { // 맨 왼쪽칸 제외
      int next_b = b;
      bool flag = false;
      while(--next_b >= 0) {
        if (v[a][next_b] == 0) {
          // 0 이라면
          continue;
        } else if (next_b <= limit || v[a][next_b] != v[a][b]) {
          // 합쳐질 수 없어, 다른 블록에 근접하게 쌓이는 경우
          int tmp = v[a][b];
          v[a][b] = 0;
          v[a][next_b + 1] = tmp;
          flag = true;
          break;
        } else {
          // 합칠 수 있다면, 기존 블록을 합친다
          v[a][b] = 0;
          v[a][next_b] *= 2;
          limit = next_b;
          flag = true;
          break;
        } 
      }

      if (!flag) {
        // 끝내 합쳐지거나 쌓이지 않아 가장자리로 쌓이는 경우
        v[a][0] = v[a][b];
        v[a][b] = 0;
      }
    }
  }

  return v;
}

void func(int depth, vector<vector<int>> v) {
  if (depth == 4) {
    vector<vector<int>> v1 = right_case(v);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        result = max(result, v1[i][j]);
      }
    }

    vector<vector<int>> v2 = left_case(v);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        result = max(result, v2[i][j]);
      }
    }
    
    vector<vector<int>> v3 = up_case(v);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        result = max(result, v3[i][j]);
      }
    }
    
    vector<vector<int>> v4 = down_case(v);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        result = max(result, v4[i][j]);
      }
    }
    
    return;
  }

  func(depth + 1, right_case(v));

  func(depth + 1, left_case(v));

  func(depth + 1, up_case(v));

  func(depth + 1, down_case(v));
}

int main() {
  cin >> N;

  vector<vector<int>> v(N, vector<int>(N));
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> v[i][j];
    }
  }

  func(0, v);

  // vector<vector<int>> v1 = right_case(v);
  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < N; j++) {
  //     cout << v1[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "=================\n";

  // vector<vector<int>> v2 = left_case(v);
  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < N; j++) {
  //     cout << v2[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "=================\n";

  // vector<vector<int>> v3 = up_case(v);
  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < N; j++) {
  //     cout << v3[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "=================\n";

  // vector<vector<int>> v4 = down_case(v);
  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < N; j++) {
  //     cout << v4[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "=================\n";
  
  cout << result;

  return 0;
}