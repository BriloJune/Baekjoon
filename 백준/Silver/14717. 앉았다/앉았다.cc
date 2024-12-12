#include <iostream>

using namespace std;

int a, b;

int main() {
	cin >> a >> b;
	cout << fixed;
	cout.precision(3);
	if (a == b) {
		float ans = (float)(153 - 10 + a) / 153;
		cout << ans << '\n';
	}
	else {
		int cnt = 0;
		for (int i = 1; i <= 10; i++) {
			for (int j = i + 1; j <= 10; j++) {
				if (i == j) continue;
				if ((a + b) % 10 > (i + j) % 10) {
					if (a != i && b != j && a != j && b != i) {
						cnt += 4;
					}
					else {
						cnt += 2;
					}
				}
			}
		}
		cout << (float)cnt / 153 << '\n';
	}
}