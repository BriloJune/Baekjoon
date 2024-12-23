#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> graph[1001]; // 인접 리스트
bool visited[1001]; // 방문 여부 확인

// DFS 함수
void dfs(int v, vector<int>& result) {
    visited[v] = true; 
    result.push_back(v); 
    
    for (int next : graph[v]) {
        if (!visited[next]) {
            dfs(next, result);
        }
    }
}

// BFS 함수
vector<int> bfs(int start) {
    vector<int> result;
    queue<int> q;
    fill(visited, visited + 1001, false); // 방문 배열 초기화
    
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        result.push_back(current);

        for (int next : graph[current]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return result;
}

int main() {
    int N, M, V;
    cin >> N >> M >> V;

    // 그래프 입력
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // 양방향 간선
    }

    // 각 정점의 인접 리스트 정렬
    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    // DFS 수행
    vector<int> dfs_result;
    fill(visited, visited + 1001, false); // 방문 배열 초기화
    dfs(V, dfs_result);

    // BFS 수행
    vector<int> bfs_result = bfs(V);

    // 결과 출력
    for (int v : dfs_result) {
        cout << v << " ";
    }
    cout << endl;

    for (int v : bfs_result) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
