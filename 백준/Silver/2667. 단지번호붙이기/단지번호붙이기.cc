#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> map;
vector<vector<bool>> visited;
int dx[4] = {0, 0, -1, 1}; // 상하좌우
int dy[4] = {-1, 1, 0, 0}; 

int dfs(int x, int y) {
    visited[x][y] = true;
    int count = 1; // 현재 집 포함

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < N) { // 지도 범위 체크
            if (!visited[nx][ny] && map[nx][ny] == 1) {
                count += dfs(nx, ny); // 연결된 집 탐색
            }
        }
    }

    return count;
}

int main() {
    cin >> N;

    map.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < N; j++) {
            map[i][j] = row[j] - '0'; // 문자 -> 숫자 변환
        }
    }

    vector<int> complexes; // 각 단지의 집 수 저장

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && map[i][j] == 1) {
                int houseCount = dfs(i, j);
                complexes.push_back(houseCount);
            }
        }
    }

    sort(complexes.begin(), complexes.end()); // 단지별 집 수 오름차순 정렬

    cout << complexes.size() << "\n"; // 단지 수 출력
    for (int count : complexes) {
        cout << count << "\n";
    }

    return 0;
}
