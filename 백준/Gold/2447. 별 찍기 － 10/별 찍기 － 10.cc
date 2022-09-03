#include <iostream>
using namespace std;

int N;

bool user[6600][6600] = { true };

void star(int a, int b, int aa, int bb) {
  int size = aa + 1 - a;
  int tmp = size / 3;
  if (size == 3) {
    user[a + 1][b + 1] = false;
  }
  else {
    for (int i = a + tmp; i <= aa - tmp; i++) {
      for (int j = b + tmp; j <= bb - tmp; j++) {
        user[i][j] = false;
      }
    }
    star(a, b, a + tmp - 1, b + tmp - 1);
    star(a + tmp, b, aa - tmp, b + tmp - 1);
    star(aa - tmp + 1, b, aa, b + tmp - 1);
    
    star(a, b + tmp, a + tmp - 1, bb - tmp);
    
    star(aa - tmp + 1, b + tmp, aa, bb - tmp);
    
    star(a, bb - tmp + 1, a + tmp - 1, bb);
    star(a + tmp, bb - tmp + 1, aa - tmp, bb);
    star(aa - tmp + 1, bb - tmp + 1, aa, bb);
  }
}

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      user[i][j] = true;
    }
  }
  
  star(0, 0, N - 1, N - 1);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (user[i][j])
        cout << "*";
      else 
        cout << " ";
    }
    cout << "\n";
  }

  return 0;
}