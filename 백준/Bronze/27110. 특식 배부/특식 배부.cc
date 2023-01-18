#include <iostream>
using namespace std;

int main() {
    int N, a, b, c;
    cin >> N >> a >> b >> c;
    
    cout << min(a, N) + min(b, N) + min(c, N);
    
    return 0;
}