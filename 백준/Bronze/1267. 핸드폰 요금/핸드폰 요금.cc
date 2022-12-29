#include <iostream>
#include <vector>
using namespace std;

int N;

int main() {
    cin >> N;
    int tmp;
    int y = 0;
    int m = 0;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        y += (tmp / 30 + 1) * 10;
        m += (tmp / 60 + 1) * 15;
    }
    
    if (y == m) {
        cout << "Y M " << y;
    }
    else if (m > y) {
        cout << "Y " << y;
    }
    else {
        cout << "M " << m;
    }
    
    return 0;
}