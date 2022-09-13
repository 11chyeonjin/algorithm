#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int min_value = min(a, min(b, c));
    int max_value = max(a, max(b, c));
    
    cout << min_value << " ";
    if (a != min_value && a != max_value)
        cout << a << " ";
    if (b != min_value && b != max_value)
       cout << b << " ";
    if (c != min_value && c != max_value)
       cout << c << " ";
    cout << max_value << " ";
    return 0;
}