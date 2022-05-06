#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    map<int, int> lt;
    lt[0]=0;
    for (auto loop : lottos) {
        if (loop==0) lt[loop]++;
        else lt[loop]=2;
    }
    for (auto loop : win_nums) {
        lt[loop]--;
    }
    // 번호 맞으면 = 1, 안맞았으면 2 혹은 -1
    
    int wincnt=0;
    for (auto i = lt.begin() ; i != lt.end() ; i++) {
        if (i->first==0) continue;
        if (i->second==1) wincnt++;
    }
    
    int unknown=lt[0];
    switch(wincnt+unknown) // max
    {
        case 6:
            answer.push_back(1);
            break;
        case 5:
            answer.push_back(2);
            break;
        case 4:
            answer.push_back(3);
            break;
        case 3:
            answer.push_back(4);
            break;
        case 2:
            answer.push_back(5);
            break;
        default:
            answer.push_back(6);
    }
    
    switch(wincnt) // min
    {
        case 6:
            answer.push_back(1);
            break;
        case 5:
            answer.push_back(2);
            break;
        case 4:
            answer.push_back(3);
            break;
        case 3:
            answer.push_back(4);
            break;
        case 2:
            answer.push_back(5);
            break;
        default:
            answer.push_back(6);
    }
    
    
    return answer;
}