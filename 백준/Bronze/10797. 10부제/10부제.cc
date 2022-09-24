#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int result = 0;
    int in;
    for (int i = 0; i < 5; i++) {
        cin >> in;
        if (n == in)
            result++;
    }
    cout << result;
    
    return 0;
}