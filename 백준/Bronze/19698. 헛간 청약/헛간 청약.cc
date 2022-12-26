#include <iostream>
using namespace std;

int main() {
    int N, W, H, L;
    cin >> N >> W >> H >> L;
    int value = (W / L) * (H / L);
    cout << min(value, N);
    return 0;
}