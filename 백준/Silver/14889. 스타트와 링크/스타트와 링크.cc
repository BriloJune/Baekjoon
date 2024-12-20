#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
int stat[20][20]; // 능력치 배열
int minDiff = INT32_MAX;
vector<int> teamStart, teamLink;

void calculateDifference() {
    int startScore = 0, linkScore = 0;

    // 스타트 팀 능력치 계산
    for (int i = 0; i < teamStart.size(); i++) {
        for (int j = 0; j < teamStart.size(); j++) {
            startScore += stat[teamStart[i]][teamStart[j]];
        }
    }

    // 링크 팀 능력치 계산
    for (int i = 0; i < teamLink.size(); i++) {
        for (int j = 0; j < teamLink.size(); j++) {
            linkScore += stat[teamLink[i]][teamLink[j]];
        }
    }

    // 두 팀의 능력치 차이 계산
    minDiff = min(minDiff, abs(startScore - linkScore));
}

void backtrack(int idx, int count) {
    // 팀이 완성되면 다른 팀은 자동으로 구성됨
    if (count == N / 2) {
        teamLink.clear();
        for (int i = 0; i < N; i++) {
            if (find(teamStart.begin(), teamStart.end(), i) == teamStart.end()) {
                teamLink.push_back(i);
            }
        }
        calculateDifference();
        return;
    }

    // 백트래킹: 팀 구성
    for (int i = idx; i < N; i++) {
        teamStart.push_back(i); // 현재 인원을 스타트 팀에 추가
        backtrack(i + 1, count + 1);
        teamStart.pop_back(); // 되돌리기
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> stat[i][j];
        }
    }

    backtrack(0, 0); // 팀 구성 시작
    cout << minDiff << endl;

    return 0;
}
