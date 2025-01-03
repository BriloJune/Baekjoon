#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, S, M;
    cin >> N >> S >> M;
    vector<int> V(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> V[i];
    }

    // DP 배열 초기화
    vector<vector<bool>> dp(N + 1, vector<bool>(M + 1, false));
    dp[0][S] = true;

    // DP 계산
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (dp[i - 1][j]) {
                if (j + V[i] <= M) {
                    dp[i][j + V[i]] = true; // 볼륨 증가
                }
                if (j - V[i] >= 0) {
                    dp[i][j - V[i]] = true; // 볼륨 감소
                }
            }
        }
    }

    // 결과 계산
    int maxVolume = -1;
    for (int j = 0; j <= M; j++) {
        if (dp[N][j]) {
            maxVolume = max(maxVolume, j);
        }
    }

    cout << maxVolume << endl;
    return 0;
}
