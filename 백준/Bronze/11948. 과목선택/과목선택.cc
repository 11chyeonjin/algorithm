#include <iostream>
using namespace std;

int main() {
    int in;
    int result = 0;
    int min_value = 101;
    for (int i = 0; i < 4; i++) {
        cin >> in;
        min_value = min(min_value, in);
        result += in;
    }
    result -= min_value;
    int in1, in2;
    cin >> in1 >> in2;
    result += max(in1, in2);
    cout << result;
    return 0;
}