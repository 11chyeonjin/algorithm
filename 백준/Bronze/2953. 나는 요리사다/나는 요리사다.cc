#include <iostream>
using namespace std;

int main() {
    int in;
    int who;
    int max = -1;
    for (int i = 1; i <= 5; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            cin >> in;
            sum += in;
        }
        if (max < sum) {
            max = sum;
            who = i;
        }
    }
    
    cout << who << " " << max;
    return 0;
}