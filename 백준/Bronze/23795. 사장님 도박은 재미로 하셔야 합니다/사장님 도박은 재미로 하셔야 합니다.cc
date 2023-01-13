#include <iostream>
using namespace std;

int main() {
    int result = 0;
    int tmp;
    while(1) {
        cin >> tmp;
        if (tmp == -1)
            break;
        result += tmp;
    }
    cout << result;
    return 0;
}