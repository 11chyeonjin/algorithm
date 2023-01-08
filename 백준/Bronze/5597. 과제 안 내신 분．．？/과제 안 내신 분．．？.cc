#include <iostream>
using namespace std;

bool user[31] = { 0, };

int main() {
    int N = 28;
    int tmp;
    while(N--) {
        cin >> tmp;
        user[tmp] = true;
    }
    
    for (int i = 1; i < 31; i++) {
        if (!user[i])
            cout << i << "\n";
    }
    
    return 0;
}