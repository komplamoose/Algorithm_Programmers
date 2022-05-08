#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int> ,greater<int>> PQ;
    for (const auto& loop : scoville) {
        PQ.push(loop);
    }
    
    while(PQ.size()!=1) {
        if (PQ.top()>=K) return answer;
        int a=PQ.top(); PQ.pop();
        int b=PQ.top()*2; PQ.pop();
        int temp = a+b;
        PQ.push(temp);
        answer++;
    }
    
    if (PQ.top()>K) return answer;
    else return -1;
}