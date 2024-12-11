#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void modifyVec(vector<int>& vec) {
	int sum = 0;
	for (int v : vec) {
		sum += v;
	}
	int Over = sum - 100;
	for (int i = 0; i < vec.size()-1; i++) {
		for (int j = i+1; j < vec.size(); j++) {
			if (vec[i] + vec[j] == Over)
			{
				vec.erase(vec.begin() + j);
				vec.erase(vec.begin() + i);
				return;
			}
		}
	}
}

int main(){
	vector<int> height;
	int n;
	for (int i = 0; i < 9; i++) {
		cin >> n;
		height.push_back(n);
	}
	modifyVec(height);
	sort(height.begin(), height.end());
	for (int rmVec : height)
		cout << rmVec << endl;
}