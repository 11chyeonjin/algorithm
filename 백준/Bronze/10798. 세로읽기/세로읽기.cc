#include <iostream>
#include <algorithm>
using namespace std;

char user[5][15];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    string in;
    int max_size = -1;
    fill(&user[0][0], &user[4][15], '.');
    for (int i = 0; i < 5; i++) {
        cin >> in;
        int string_size = in.size();
        max_size = max(max_size, string_size);
        for (int j = 0; j < string_size ; j++) {
            user[i][j] = in[j];
        }
    }
    
    for (int i = 0; i < max_size; i++) {
        for (int j = 0; j < 5; j++) {
            if (user[j][i] != '.')
                cout << user[j][i];
        }
    }
    
    return 0;
}