#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, vector<string>> reporter; // Key 유저를 신고한 사람 저장
    for (const auto& loop : report) {
        istringstream iss(loop);
        string ter; // 신고자
        string ted; // 피신고자
        iss >> ter >> ted;
        if (find(reporter[ted].begin(), reporter[ted].end(),ter)==reporter[ted].end())
            reporter[ted].push_back(ter);
    }
    map<string, int> susin;
    for (const auto& loop : id_list) {
        susin[loop]=0;
    }
    for (auto i=reporter.begin(); i!=reporter.end(); i++) {
        if (i->second.size()>=k){
            for (const auto& loop : i->second) {
                susin[loop]++;
            }
        }
    }
    
    for (auto loop : id_list) {
        answer.push_back(susin[loop]);
    }
    
    return answer;
}