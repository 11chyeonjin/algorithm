#include <iostream>
using namespace std;

int main() {
    
    int max_value = -1;
    pair<int,int> where;
    
    int tmp;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> tmp;
            if (max_value < tmp) {
                max_value = tmp;
                where = {i, j};
            }
        }
    }
    
    cout << max_value << "\n" << where.first + 1 << " " << where.second + 1;
}