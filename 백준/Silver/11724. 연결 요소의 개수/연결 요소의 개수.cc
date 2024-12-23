#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph; // 그래프를 인접 리스트로 표현
vector<bool> visited;      // 방문 여부 기록

// DFS 구현
void dfs(int node) {
    visited[node] = true; // 현재 노드를 방문 처리
    for (int next : graph[node]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    // 그래프 초기화
    graph.resize(N + 1);
    visited.resize(N + 1, false);

    // 간선 입력받기
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // 무방향 그래프이므로 양방향 간선 추가
    }

    int connectedComponents = 0;

    // 각 정점에서 DFS 실행
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i); // 새로운 연결 요소 발견
            connectedComponents++;
        }
    }

    cout << connectedComponents << endl;
    return 0;
}
