#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    int in;
    for (int i = 0; i < 5; i++) {
        cin >> in;
        if (in < 40)
            in = 40;
        sum += in;
    }
    cout << sum / 5;
    
    return 0;
}