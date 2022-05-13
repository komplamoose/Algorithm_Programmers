#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int pick=nums.size()/2;
    unordered_set<int> s;
    for (auto loop: nums) {
        s.insert(loop);
    }
    
    if (pick>s.size()){
        answer=s.size();
    }else{
        answer=pick;
    }
    return answer;
}