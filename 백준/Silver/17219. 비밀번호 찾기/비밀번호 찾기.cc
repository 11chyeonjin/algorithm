#include <iostream>
#include <map>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  
  map <string, string> user;
  int n, m;
  cin >> n >> m;

  string site, pw;
  while(n--) {
    cin >> site >> pw;
    user.insert({site, pw});
  }
  while(m--) {
    cin >> site;
    cout << user[site] << "\n";
  }

  return 0;
}