#include <iostream>

using namespace std;

void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

int main()
{
	int M;
	int a, b;
	int cup[3] = { 1,0,0 };
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		swap(cup[a - 1], cup[b - 1]);
	}
	for (int i = 0; i < 3; i++) {
		if (cup[i] == 1)
			cout << i + 1;
	}

}

