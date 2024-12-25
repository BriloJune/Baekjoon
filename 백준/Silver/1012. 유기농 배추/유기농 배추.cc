#include <iostream>
#include <vector>
#include <cstring> // memset
using namespace std;

int T, M, N, K;
int field[50][50]; // 배추밭
bool visited[50][50]; // 방문 여부
int dx[4] = {0, 0, -1, 1}; // 상하좌우 이동
int dy[4] = {-1, 1, 0, 0};

// DFS 함수
void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        // 유효 범위 내에 있고, 배추가 있으며, 아직 방문하지 않았다면 탐색
        if (nx >= 0 && nx < M && ny >= 0 && ny < N && field[nx][ny] == 1 && !visited[nx][ny]) {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> T; // 테스트 케이스 수

    while (T--) {
        cin >> M >> N >> K; // 가로, 세로, 배추 개수
        memset(field, 0, sizeof(field)); // 배추밭 초기화
        memset(visited, false, sizeof(visited)); // 방문 여부 초기화

        // 배추 위치 입력
        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            field[x][y] = 1;
        }

        int wormCount = 0;

        // 모든 좌표를 탐색
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                // 배추가 있고, 아직 방문하지 않았다면 DFS 시작
                if (field[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j);
                    wormCount++; // 새로운 그룹 발견 -> 지렁이 추가
                }
            }
        }

        cout << wormCount << endl; // 결과 출력
    }

    return 0;
}
