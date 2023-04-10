#include <iostream>
using namespace std;

int N;
int coin[6] = { 500, 100, 50, 10, 5, 1 };

int main() {
    cin >> N;
    
    int result = 0;
    
    N = 1000 - N;
    for (int i = 0; i < 6; i++) {
        result += N / coin[i];
        N %= coin[i];
    }
    
    cout << result;
    
    return 0;
}