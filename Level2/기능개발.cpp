#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<pair<int, int>> schedule;
    
    for (int i=0; i<speeds.size(); i++) {
        schedule.push(make_pair(progresses[i], speeds[i]));
    }
    
    while(!schedule.empty()) {
        int temp=schedule.front().first;
        int days=0;
        int cnt=0;
        while(temp<100){ // 큐 앞에 것 빠져나오도록 함
            int step=schedule.front().second;
            temp+=step;
            days++;
        }
        schedule.pop();
        cnt++; // 최소 하나 빠져나옴
        while(1) {
            if (schedule.front().first+(schedule.front().second*days)>=100){
                cnt++;
                schedule.pop();;
            }else {
                break;
            }
        }
        answer.push_back(cnt);
    }
    
    return answer;
}