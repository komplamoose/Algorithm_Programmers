#include <string>
#include <vector>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.first==b.first) return a.second > b.second;
        return a.first > b.first;
    }
};

struct cmp2 {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.second==b.second) return a.first > b.first;
        return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> blockq; // 입장시간 기준으로 정렬
    for (const auto& loop : jobs) {
        blockq.push(make_pair(loop[0], loop[1]));
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp2> readyq; // 레디큐
    
    
    int cnt=0; // 실행 시점
    bool exist=false; // 현재 프로그램이 실행중인지
    int limit=0;
    while(1) {
        if (readyq.empty()&&blockq.empty()) break;
        pair<int, int> current;
        while(!blockq.empty()&&blockq.top().first<=cnt) {
            readyq.push(make_pair(blockq.top().first,blockq.top().second));
            blockq.pop();
        }
        if (cnt>=limit&&!readyq.empty()){
            current = readyq.top(); readyq.pop();
            limit=cnt+current.second;
            answer+=cnt+current.second-current.first;
        }
        cnt++;
    }
    
    answer/=jobs.size();
    
    return answer;
}