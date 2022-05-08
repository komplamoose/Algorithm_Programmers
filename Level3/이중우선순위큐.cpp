#include <string>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int, greater<int>> s;
    
    for (const auto& loop : operations) {
        istringstream iss(loop);
        char order; int nums;
        iss >> order >> nums;
        
        if (order=='I') {
            s.insert(nums);
        }else {
            if (!s.empty()) {
                if (nums==1) { // 최대값
                    s.erase(s.begin());
                }else {
                    s.erase(--s.end());
                }
            }
        }
    }
    
    if (s.empty()) {
        answer.push_back(0); answer.push_back(0);
    }else {
        answer.push_back(*s.begin()); answer.push_back(*(--s.end()));
    }
    
    return answer;
}