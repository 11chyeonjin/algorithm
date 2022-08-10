#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  map <string, int> m_str;
  map <int, string> m_int;

  string strin;
  for (int i = 1; i <= N; i++) {
    cin >> strin;
    m_int.insert({i, strin});
    m_str.insert({strin, i});
  }
  for (int i = 0; i < M; i++) {
    cin >> strin;
    if (isdigit(strin[0])) {
      int in = stoi(strin);
      cout << m_int[in] << "\n";
    }
    else {
      cout << m_str[strin] << "\n";
    }
  }
  return 0;
}