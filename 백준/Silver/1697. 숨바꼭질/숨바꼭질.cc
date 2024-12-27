#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int bfs(int N, int K) {
    vector<bool> visited(100001, false); // 방문 여부 확인 배열
    queue<pair<int, int>> q; // {위치, 시간}
    
    q.push({N, 0}); // 초기 위치와 시간
    visited[N] = true;

    while (!q.empty()) {
        int pos = q.front().first;
        int time = q.front().second;
        q.pop();

        if (pos == K) return time; // 동생 위치에 도달하면 시간 반환

        // 이동 가능한 경우 탐색
        if (pos - 1 >= 0 && !visited[pos - 1]) {
            q.push({pos - 1, time + 1});
            visited[pos - 1] = true;
        }
        if (pos + 1 <= 100000 && !visited[pos + 1]) {
            q.push({pos + 1, time + 1});
            visited[pos + 1] = true;
        }
        if (pos * 2 <= 100000 && !visited[pos * 2]) {
            q.push({pos * 2, time + 1});
            visited[pos * 2] = true;
        }
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    cout << bfs(N, K) << '\n';
    return 0;
}
