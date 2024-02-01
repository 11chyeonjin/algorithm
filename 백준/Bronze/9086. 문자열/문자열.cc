#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    string tmp;
    while(T--) {
        cin >> tmp;
        cout << tmp[0] << tmp[tmp.size() - 1] << "\n";
    }
    
    return 0;
}