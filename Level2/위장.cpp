#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map<string, int> hs;
    for (auto loop : clothes) { 
        hs[loop[1]]++;
    }
    int per=1;
    for (auto i=hs.begin(); i!=hs.end(); i++) {
        per*=(i->second+1);
    }
    
    answer=per-1;
    return answer;
}