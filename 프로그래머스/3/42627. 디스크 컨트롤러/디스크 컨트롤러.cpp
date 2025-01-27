#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    // 작업을 요청 시각 기준으로 정렬
    sort(jobs.begin(), jobs.end());

    int time = 0;          // 현재 시각
    int total_time = 0;    // 총 반환 시간
    int i = 0;             // 작업 인덱스
    int n = jobs.size();   // 작업 수

    // 최소 힙: 소요 시간(duration)을 기준으로 정렬
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap;

    while (i < n || !min_heap.empty()) {
        // 현재 시각까지 요청된 작업을 힙에 추가
        while (i < n && jobs[i][0] <= time) {
            min_heap.push({jobs[i][1], jobs[i][0]}); // {소요 시간, 요청 시각}
            i++;
        }

        if (!min_heap.empty()) {
            // 힙에서 소요 시간이 가장 짧은 작업을 꺼냄
            auto [duration, start] = min_heap.top();
            min_heap.pop();

            // 작업 처리
            time += duration;                  // 현재 시각 갱신
            total_time += time - start;        // 반환 시간 계산
        } else {
            // 대기 중인 작업이 없으면 다음 작업의 요청 시각으로 이동
            time = jobs[i][0];
        }
    }

    // 반환 시간 평균의 정수 부분 반환
    return total_time / n;
}

int main() {
    vector<vector<int>> jobs = {{0, 3}, {1, 9}, {3, 5}};
    cout << solution(jobs) << endl; // 출력: 8
    return 0;
}
