#include <iostream>

using namespace std;

// bingo 배열을 참조로 받는 함수
int checkBingo(int (&bingo)[5][5]) {
    int bingoCount = 0;

    // 가로 줄 검사
    for (int i = 0; i < 5; i++) {
        bool isBingo = true;
        for (int j = 0; j < 5; j++) {
            if (bingo[i][j] != 0) {
                isBingo = false;
                break;
            }
        }
        if (isBingo) {
            bingoCount++;
        }
    }

    // 세로 줄 검사
    for (int j = 0; j < 5; j++) {
        bool isBingo = true;
        for (int i = 0; i < 5; i++) {
            if (bingo[i][j] != 0) {
                isBingo = false;
                break;
            }
        }
        if (isBingo) {
            bingoCount++;
        }
    }

    // 대각선 검사 (왼쪽 위 -> 오른쪽 아래)
    bool isBingo = true;
    for (int i = 0; i < 5; i++) {
        if (bingo[i][i] != 0) {
            isBingo = false;
            break;
        }
    }
    if (isBingo) {
        bingoCount++;
    }

    // 대각선 검사 (오른쪽 위 -> 왼쪽 아래)
    isBingo = true;
    for (int i = 0; i < 5; i++) {
        if (bingo[i][4 - i] != 0) {
            isBingo = false;
            break;
        }
    }
    if (isBingo) {
        bingoCount++;
    }

    return bingoCount;
}

int main() {
    int bingo[5][5];
    int call[25];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> bingo[i][j];
        }
    }

    for (int i = 0; i < 25; i++) {
        cin >> call[i];
    }

    int count = 0;
    for (int k = 0; k < 25; k++) { // 호출된 숫자 순서대로 확인
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (bingo[i][j] == call[k]) {
                    bingo[i][j] = 0; // 숫자를 제거
                    count = checkBingo(bingo); // 현재 빙고 개수 확인
                    if (count >= 3) { // 빙고가 3개 이상이면 종료
                        cout << k + 1 << endl;
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}
