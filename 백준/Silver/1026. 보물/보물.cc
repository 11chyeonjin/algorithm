#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int S = 0;
int N;

vector<int> A;
vector<int> B;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> N;
  int numIn;
  for (int i = 0; i < N; i++) {
    cin >> numIn;
    A.push_back(numIn);
  }
  for (int i = 0; i < N; i++) {
    cin >> numIn;
    B.push_back(numIn);
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  for (int i = 0; i < N; i++) {
    S += B[N - i - 1] *  A[i];
  }

  cout << S;
  return 0;
}