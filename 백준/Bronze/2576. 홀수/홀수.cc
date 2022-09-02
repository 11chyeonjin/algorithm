#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int sum = 0;
    int min_value = 999;
    int in;
    for (int i = 0; i < 7; i++) {
        cin >> in;
        if (in % 2) {
            sum += in;
            min_value = min(min_value, in);
        }
    }
    if (!sum)
        cout << -1;
    else {
        cout << sum << "\n" << min_value;
    }
    
    return 0;
}