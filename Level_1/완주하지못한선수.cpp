// 레벨 1, 완주하지 못한 선수
// https://programmers.co.kr/learn/courses/30/lessons/42576
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> temp;
    for (auto loop : participant) {
        temp[loop]++;
    }
    for (auto loop : completion) {
        temp[loop]--;
    }
    for (auto i = temp.begin(); i!=temp.end(); i++){
        if (i->second==1) answer+=i->first;
    }
    
    
    return answer;
}