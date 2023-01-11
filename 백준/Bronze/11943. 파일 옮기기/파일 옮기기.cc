#include <iostream>
using namespace std;

int a, b, c, d;

int main() {
    cin >> a >> b >> c >> d;
    cout << min(a + d, b + c);
    
    return 0;
}