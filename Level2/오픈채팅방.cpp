#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> id_name;
    vector<pair<string,int>> room; // 입장, 퇴장 기록. 0이면 입장 1이면 퇴장 
    for (const auto& loop : record) {
        string command, id, name;
        istringstream iss(loop);
        iss >> command >> id >> name;
        if (command=="Enter") {
            id_name[id]=name;
            room.push_back(make_pair(id,0));
        }else if (command=="Leave") {
            room.push_back(make_pair(id,1));
        }else if (command=="Change") {
            id_name[id]=name;
        }
    }
    
    for (const auto& loop : room) {
        string input;
        if (loop.second==0) { // Enter
            input = id_name[loop.first] + "님이 들어왔습니다.";
        }else {
            input = id_name[loop.first] + "님이 나갔습니다.";
        }
        answer.push_back(input);
    }
    
    return answer;
}