#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int day;
    cin >> day;

    vector<int> T(day + 1), P(day + 1), dp(day + 2, 0);

    for (int i = 1; i <= day; i++) {
        cin >> T[i] >> P[i];
    }

    // 뒤에서부터 DP 계산
    for (int i = day; i >= 1; i--) {
        if (i + T[i] - 1 <= day) { // 상담 가능
            dp[i] = max(dp[i + 1], P[i] + dp[i + T[i]]);
        } else { // 상담 불가능
            dp[i] = dp[i + 1];
        }
    }

    cout << dp[1];
    return 0;
}
