#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    unordered_map<int, pair<int,int>> m;
    m.insert(make_pair(1,make_pair(1,1)));
    m.insert(make_pair(2,make_pair(1,2)));
    m.insert(make_pair(3,make_pair(1,3)));
    m.insert(make_pair(4,make_pair(2,1)));
    m.insert(make_pair(5,make_pair(2,2)));
    m.insert(make_pair(6,make_pair(2,3)));
    m.insert(make_pair(7,make_pair(3,1)));
    m.insert(make_pair(8,make_pair(3,2)));
    m.insert(make_pair(9,make_pair(3,3)));
    m.insert(make_pair(10,make_pair(4,1))); // *
    m.insert(make_pair(12,make_pair(4,3))); // #
    m.insert(make_pair(0,make_pair(4,2)));
    int ltp=10; // *
    int rtp=12; // #
    for (int i=0; i<numbers.size(); i++) {
        int cmd=numbers[i];
        if (cmd==1||cmd==4||cmd==7){
            answer+="L";
            ltp=cmd;
        }
        else if (cmd==3||cmd==6||cmd==9){
            answer+="R";
            rtp=cmd;
        }
        else{
            if (abs(m[ltp].first-m[cmd].first)+abs(m[ltp].second-m[cmd].second)==abs(m[rtp].first-m[cmd].first)+abs(m[rtp].second-m[cmd].second)){
                if (hand=="left"){
                    answer+="L";
                    ltp=cmd;
                }else{
                    answer+="R";
                    rtp=cmd;
                }
            }else if (abs(m[ltp].first-m[cmd].first)+abs(m[ltp].second-m[cmd].second)<abs(m[rtp].first-m[cmd].first)+abs(m[rtp].second-m[cmd].second)) {
                answer+="L";
                ltp=cmd;
            }else {
                answer+="R";
                rtp=cmd;
            }
        }
    }
    return answer;
}