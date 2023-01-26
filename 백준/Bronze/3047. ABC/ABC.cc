#include <iostream>
using namespace std;

int main() {
    int dd[3];
    cin >> dd[0] >> dd[1] >> dd[2];
    int a, b, c;
    a = min(dd[0], min(dd[1], dd[2]));
    c = max(dd[0], max(dd[1], dd[2]));
    for (int i = 0; i < 3; i++) {
        if (dd[i] != a && dd[i] != c)
            b = dd[i];
    }
    string tmp;
    cin >> tmp;
    
    if (tmp[0] == 'A'){
        if (tmp[1] == 'B')
            cout << a << " " << b << " " << c;
        else
            cout << a << " " << c << " " << b;
    }
    else if (tmp[0] == 'B') {
        if (tmp[1] == 'A')
            cout << b << " " << a << " " << c;
        else
            cout << b << " " << c << " " << a;
    }
    else {
        if (tmp[1] == 'A')
            cout << c << " " << a << " " << b;
        else
            cout << c << " " << b << " " << a;
    }
    
    return 0;
}