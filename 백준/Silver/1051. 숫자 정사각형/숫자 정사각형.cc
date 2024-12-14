#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 정사각형 크기를 계산하는 함수
int calculateSize(const vector<vector<int>> &board, int startX, int startY) {
    int maxSize = 1; // 최소 정사각형 크기는 1x1
    int n = board.size();
    int m = board[0].size();
    
    // 가능한 정사각형의 최대 크기를 탐색
    int maxSide = min(n - startX, m - startY);
    for (int size = 2; size <= maxSide; size++) {
        int endX = startX + size - 1;
        int endY = startY + size - 1;

        // 꼭짓점의 값 비교
        if (board[startX][startY] == board[startX][endY] &&
            board[startX][startY] == board[endX][startY] &&
            board[startX][startY] == board[endX][endY]) {
            maxSize = size;
        }
    }
    return maxSize * maxSize; // 정사각형 넓이를 반환
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> board(N, vector<int>(M));

    // 입력 받기
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++) {
            board[i][j] = row[j] - '0'; // 문자를 숫자로 변환
        }
    }

    int maxSquare = 1; // 최소 정사각형 크기는 1x1

    // 모든 좌표에서 가능한 정사각형 크기 탐색
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            maxSquare = max(maxSquare, calculateSize(board, i, j));
        }
    }

    cout << maxSquare << endl; // 결과 출력
    return 0;
}
