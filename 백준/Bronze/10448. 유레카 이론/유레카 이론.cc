#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 삼각수를 계산하는 함수
int Tn(int n) {
    return (n * (n + 1)) / 2;
}

bool SumFunc(vector<int>& vec, int target) {
    int N = vec.size();
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            for (int k = j; k < N; k++) {
                int sum = vec[i] + vec[j] + vec[k];
                if (sum == target) {
                    return true;
                }
                if (sum > target) {
                    break; // 이미 target을 초과했으므로 더 이상 탐색할 필요 없음
                }
            }
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;

    vector<int> triangleNumbers;
    for (int i = 1; ; i++) {
        int t = Tn(i);
        if (t > 1000) break; // 문제에서 K의 최대값이 1000이므로 이를 초과하는 삼각수는 필요 없음
        triangleNumbers.push_back(t);
    }

    while (T--) {
        int K;
        cin >> K;
        if (SumFunc(triangleNumbers, K)) {
            cout << 1 << endl; // 삼각수 3개의 합으로 표현 가능
        }
        else {
            cout << 0 << endl; // 표현 불가능
        }
    }


    return 0;
}
