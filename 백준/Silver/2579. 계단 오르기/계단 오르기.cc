#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> step(n + 1, 0);
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> step[i];
    }

    dp[1] = step[1];
    if (n >= 2) {
        dp[2] = step[1] + step[2]; // 두 번째 계단 초기화
    }

    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i - 3] + step[i - 1], dp[i - 2]) + step[i];
    }

    cout << dp[n] << endl;

    return 0;
}
