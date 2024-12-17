#include <iostream>
using namespace std;

int main() {
    int seed;
    cin >> seed;

    int day[14][2]; // day[i][0]: 주가, day[i][1]: 상승/하락 여부 (1: 상승, 0: 하락)
    for (int i = 0; i < 14; i++) {
        cin >> day[i][0];
        if (i > 0) {
            // 상승: 1, 하락 또는 동일: 0
            day[i][1] = (day[i][0] > day[i - 1][0]) ? 1 : 0;
        } else {
            day[i][1] = 0; // 첫날은 비교 대상 없음
        }
    }

    // BNP 전략
    int BNP_seed = seed, BNP_stock = 0;
    for (int i = 0; i < 14; i++) {
        int max_stock = BNP_seed / day[i][0];
        BNP_stock += max_stock;
        BNP_seed -= max_stock * day[i][0];
    }
    int BNP_total = BNP_seed + BNP_stock * day[13][0]; // BNP 총 자산

    // TIMING 전략
    int Timing_seed = seed, Timing_stock = 0;
    for (int i = 3; i < 14; i++) {
        // 3일 연속 하락: 매수
        if (day[i][1] + day[i - 1][1] + day[i - 2][1] == 0) {
            int max_stock = Timing_seed / day[i][0];
            Timing_stock += max_stock;
            Timing_seed -= max_stock * day[i][0];
        }

        // 3일 연속 상승: 매도
        if (day[i][1] + day[i - 1][1] + day[i - 2][1] == 3 && Timing_stock > 0) {
            Timing_seed += Timing_stock * day[i][0];
            Timing_stock = 0;
        }
    }
    int Timing_total = Timing_seed + Timing_stock * day[13][0]; // TIMING 총 자산

    // 결과 출력
    if (Timing_total > BNP_total) {
        cout << "TIMING";
    } else if (Timing_total == BNP_total) {
        cout << "SAMESAME";
    } else {
        cout << "BNP";
    }

    return 0;
}
