#include <iostream>
using namespace std;

int sets[10] = { 0 };

int main() {
    string num;
    cin >> num;
    for (int i = 0; i < num.size(); i++) {
        sets[num[i] - '0']++;
    }
    int six_or_nine = sets[6] + sets[9];
    int max_value = -1;
    for (int i = 0; i < 10; i++) {
      if (i != 6 && i != 9)
        max_value = max(max_value, sets[i]);
    }
    if (six_or_nine % 2) {
        six_or_nine = six_or_nine / 2 + 1;
    }
    else {
        six_or_nine = six_or_nine / 2;
    }
    cout << max(max_value, six_or_nine);
    
    return 0;
}