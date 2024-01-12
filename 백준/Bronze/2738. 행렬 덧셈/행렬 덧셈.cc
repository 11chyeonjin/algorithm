#include <iostream>
using namespace std;

int sol[100][100] = { 0, };

int main() {
    int n, m;
    cin >> n >> m;
    
    int tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            sol[i][j] += tmp;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            sol[i][j] += tmp;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << sol[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}