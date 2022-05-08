#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    queue<int> stocks;
    for (const auto& loop : prices) {
        stocks.push(loop);
    }
    
    int start=0;
    while (!stocks.empty()) {
        start++;
        int cnt=0;
        int currentPrice=stocks.front(); stocks.pop();
        for (int i=start; i<prices.size(); i++) {
            if (prices[i]>=currentPrice) {
                cnt++;
            }else {
                cnt++; break;
            }
        }
        answer.push_back(cnt);
    }
    
    
    return answer;
}