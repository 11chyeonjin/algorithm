#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    vector<int> user(201, 0);
    
    int n, in, v;
    cin >> n;
    while(n--) {
        cin >> in;
        user[in + 100]++;
    }
    cin >> v;
    cout << user[v + 100];
    return 0;
}