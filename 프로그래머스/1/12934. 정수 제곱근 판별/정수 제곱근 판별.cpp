#include <string>

using namespace std;

long long solution(long long n) {
    long long i = 1;  // 0은 제곱근으로 의미 없음

    while (i * i <= n) {  
        if (i * i == n) return (i + 1) * (i + 1); // 제곱수라면 다음 제곱 반환
        i++;  
    }
    
    return -1;  // 제곱수가 아니라면 -1 반환
}
