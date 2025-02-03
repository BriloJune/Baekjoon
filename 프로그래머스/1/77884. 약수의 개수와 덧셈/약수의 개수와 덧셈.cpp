#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    for(int i=left; i<=right; i++) {
        int num = 0;
        for(int j=1; j<=i; j++) {
            if(i%j==0) {
                num++;
            }
        }
        if(num%2==0) {
            answer += i;
        }
        else if(num%2==1) {
            answer -= i; 
        }
    }
    return answer;
}