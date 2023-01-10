#include <iostream>
using namespace std;

int h, m, s, hh, ss, mm;
int result[10];

int main() {
    for (int i = 0; i < 3; i++) {
        cin >> h >> m >> s;
        cin >> hh >> mm >> ss;
        result[3 * i] = hh - h;
        result[3 * i + 1] = mm - m;
        result[3 * i + 2] = ss - s;
        if (result[3 * i + 2] < 0) {
            result[3 * i + 1] -= 1;
            result[3 * i + 2] += 60;
        }
        if (result[3 * i + 1] < 0) {
            result[3 * i] -= 1;
            result[3 * i + 1] += 60;
        }
    }
    
    for (int i = 0; i < 3; i++) {
        cout << result[3 * i] << " " << result[3 * i + 1] << " " << result[3 * i + 2] << "\n";
    }
    
    return 0;
}