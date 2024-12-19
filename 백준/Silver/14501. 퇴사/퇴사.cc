#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 최대 수익 계산을 위한 재귀 함수
int getMaxIncome(int day, const vector<int>& T, const vector<int>& P, int currentDay) {
    if (currentDay > day) {
        return 0; // 퇴사일 이후는 상담 불가
    }

    // 상담을 하지 않는 경우
    int skip = getMaxIncome(day, T, P, currentDay + 1);

    // 상담을 하는 경우
    int take = 0;
    if (currentDay + T[currentDay] - 1 <= day) { // 상담 가능
        take = P[currentDay] + getMaxIncome(day, T, P, currentDay + T[currentDay]);
    }

    // 최대값 반환
    return max(skip, take);
}

int main() {
    int day;
    cin >> day;

    vector<int> T(day + 1); // 상담 기간
    vector<int> P(day + 1); // 상담 금액

    for (int i = 1; i <= day; i++) {
        cin >> T[i] >> P[i];
    }

    int max_income = getMaxIncome(day, T, P, 1);
    cout << max_income;

    return 0;
}
