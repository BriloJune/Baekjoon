#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
int max_val = INT32_MIN;  // 최대값 초기화 (최소값으로 시작)
int min_val = INT32_MAX;  // 최소값 초기화 (최대값으로 시작)
vector<int> numbers;
int operators[4];

void Calculate(int answer, int idx) {
    if (idx == N) {  // 모든 숫자를 계산한 경우
        if (answer > max_val) max_val = answer;
        if (answer < min_val) min_val = answer;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (operators[i] > 0) {
            operators[i]--;
            if (i == 0) {  // 덧셈
                Calculate(answer + numbers[idx], idx + 1);
            } else if (i == 1) {  // 뺄셈
                Calculate(answer - numbers[idx], idx + 1);
            } else if (i == 2) {  // 곱셈
                Calculate(answer * numbers[idx], idx + 1);
            } else if (i == 3) {  // 나눗셈
                Calculate(answer / numbers[idx], idx + 1);
            }
            operators[i]++;  // 연산자 개수 복원
        }
    }
}

int main() {
    cin >> N;  // 숫자의 개수 입력
    numbers.resize(N);  // 벡터 크기 설정

    for (int i = 0; i < N; i++) {
        cin >> numbers[i];  // 숫자 입력
    }
    for (int i = 0; i < 4; i++) {
        cin >> operators[i];  // 연산자 개수 입력
    }

    Calculate(numbers[0], 1);  // 초기값과 인덱스 전달
    cout << max_val << endl;
    cout << min_val;

    return 0;
}
