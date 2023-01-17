#include <iostream>
using namespace std;

int main() {
    int n, p, result;
    cin >> n >> p;
    result = p;
    if (n >= 20)
        result = min(result, p / 100 * 75);
    if (n >= 15)
        result = min(result, p - 2000);
    if (n >= 10)
        result = min(result, p / 100 * 90);
    if (n >= 5)
        result = min(result, p - 500);
    
    if (result < 0)
        result = 0;
    
    cout << result;
    return 0;
}