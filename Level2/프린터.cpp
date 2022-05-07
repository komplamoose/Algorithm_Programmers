#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> printer;
    
    for (int i=0; i< priorities.size(); i++) {
        printer.push(make_pair(i,priorities[i]));
    }
    
    int cnt=0;
    while(!printer.empty()) {
        bool trg=false;
        pair<int, int> frt = printer.front(); printer.pop();
        queue<pair<int,int>> temp = printer;
        while(!temp.empty()) {
            if (temp.front().second>frt.second){
                trg=true;
                break;
            }else{
                temp.pop();
            }
        }
        if (trg) { // 존재한다면
            printer.push(frt);
        } else {
            cnt++;
            if (frt.first==location) return cnt;
        }
    }
    
    return answer;
}