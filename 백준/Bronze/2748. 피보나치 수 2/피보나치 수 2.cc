#include <iostream>

using namespace std;

long long d[100];

long long dp(int x) {
	if (x == 0) return 0;
	if (x == 1) return 1;
	if (d[x] != 0) return d[x];
	return d[x] = dp(x - 1) + dp(x - 2);
}

int main()
{
	int n;
	cin >> n;
	cout<< dp(n);
}