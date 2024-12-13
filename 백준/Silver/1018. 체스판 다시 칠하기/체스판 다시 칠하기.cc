#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 체스판 패턴 생성
const vector<string> chessPattern1 = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};

const vector<string> chessPattern2 = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

// 주어진 영역에서 체스판과 비교하여 다시 칠해야 하는 칸 수 계산
int calculateRepaint(const vector<string>& board, int startX, int startY, const vector<string>& pattern) {
    int repaintCount = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[startX + i][startY + j] != pattern[i][j]) {
                repaintCount++;
            }
        }
    }
    return repaintCount;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> board(N);

    // 입력받기
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    int minRepaint = -1; // 초기값을 -1로 설정

    // 가능한 모든 8x8 영역 탐색
    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
            // 두 가지 체스판 패턴 중 최소 칠해야 하는 칸 계산
            int cost1 = calculateRepaint(board, i, j, chessPattern1);
            int cost2 = calculateRepaint(board, i, j, chessPattern2);
            int currentMin = min(cost1, cost2);

            // 최소값 갱신
            if (minRepaint == -1 || currentMin < minRepaint) {
                minRepaint = currentMin;
            }
        }
    }

    cout << minRepaint << endl;
    return 0;
}
