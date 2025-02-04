#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> stk;
    
    for(int num:arr) {
        if(stk.empty()||num!=stk.top()) {
            stk.push(num);
        }
    }
    while(!stk.empty()) {
        answer.push_back(stk.top());
        stk.pop();
    }
    reverse(answer.begin(),answer.end());

    return answer;
}