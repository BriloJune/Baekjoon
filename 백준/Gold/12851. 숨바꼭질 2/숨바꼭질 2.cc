#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    // 방문 여부 및 시간 배열 초기화
    vector<int> visited(100001, -1); // 방문하지 않은 곳: -1
    vector<int> ways(100001, 0);     // 각 위치로 가는 방법의 수

    queue<int> q;
    q.push(N);
    visited[N] = 0;  // 시작 위치 방문 시간: 0초
    ways[N] = 1;     // 시작 위치로 가는 방법: 1가지

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // 세 가지 이동 방법
        vector<int> next_positions = {current - 1, current + 1, current * 2};

        for (int next : next_positions) {
            // 유효한 위치인지 확인
            if (next >= 0 && next <= 100000) {
                // 아직 방문하지 않은 경우
                if (visited[next] == -1) {
                    visited[next] = visited[current] + 1;
                    ways[next] = ways[current]; // 방법의 수는 현재 위치에서 이동한 경우와 같음
                    q.push(next);
                } 
                // 이미 방문했지만 최단 시간에 도달한 경우
                else if (visited[next] == visited[current] + 1) {
                    ways[next] += ways[current]; // 방법의 수를 누적
                }
            }
        }
    }

    // 결과 출력
    cout << visited[K] << '\n'; // 최단 시간
    cout << ways[K] << '\n';    // 최단 시간으로 도달하는 방법의 수

    return 0;
}
