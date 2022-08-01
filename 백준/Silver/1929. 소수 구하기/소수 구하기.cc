#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int M, N;
	cin >> M >> N;
	vector<bool> user(1000001, true);
	user[0] = false;
	user[1] = false;
	for (int i = 2; i <= sqrt(N); i++) {
		if (user[i] == false) {
			continue;
		}
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				user[i] = false;
				break;
			}
		}

		if (user[i] == false) {
			continue;
		}

		for (int j = i + i; j <= N; j += i)
			user[j] = false;
	}
	for (int i = M; i <= N; i++) {
		if (user[i])
			cout << i << "\n";
	}
	return 0;
}
