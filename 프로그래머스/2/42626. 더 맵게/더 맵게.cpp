#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> pq(scoville.begin(),scoville.end());
    while(pq.size()>1&&pq.top()<K) {
        int sum = 0;
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        sum=first+(second*2);
        pq.push(sum);
        answer++;
    }
    if(pq.top()<K)
        return answer = -1;
    return answer;
}