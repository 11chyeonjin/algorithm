#include <iostream>
using namespace std;

int main() {
    string name;
    int age, weight;
    while(1) {
        cin >> name >> age >> weight;
        if (age == 0 && weight == 0)
            break;
        if (age > 17 || weight >= 80) {
            cout << name << " " << "Senior\n";
        }
        else {
            cout << name << " " << "Junior\n";
        }
    }
    
    return 0;
}