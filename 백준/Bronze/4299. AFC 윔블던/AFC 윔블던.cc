#include <iostream>
using namespace std;

int main() {
    int _sum, _sub;
    cin >> _sum >> _sub;
    
    if ((_sum + _sub) < 0) {
        cout << -1;
        return 0;
    }
    
    if ((_sum - _sub) < 0) {
        cout << -1;
        return 0;
    }
    
    if ((_sum + _sub) % 2) {
        cout << -1;
        return 0;
    }
    
    if ((_sum - _sub) % 2) {
        cout << -1;
        return 0;
    }
    
    cout << (_sum + _sub) / 2 << " " << (_sum - _sub) / 2;
    
    return 0;
}