#include <iostream>
using namespace std;

int main() {
    int in;
    int sum1 = 0;
    int sum2 = 0;
    for (int j = 0; j < 4; j++) {
        cin >> in;
        sum1 += in;
    }
    for (int j = 0; j < 4; j++) {
        cin >> in;
        sum2 += in;
    }
    cout << max(sum1, sum2);
    
    return 0;
}