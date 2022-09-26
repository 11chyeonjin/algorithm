#include <iostream>
using namespace std;

int result[5];

int main() {
    int L, P;
    cin >> L >> P;
    
    int in;
    for (int i = 0; i < 5; i++) {
        cin >> in;
        result[i] = in - L * P;
    }
    
    for (int i = 0; i < 5; i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}