#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    unordered_map<int, int> nums;
    for (int i=0; i<10; i++) {
        nums[i]=0;
    }
    
    for (auto loop : numbers) {
        nums[loop]=1;
    }
    
    for (auto i=nums.begin(); i!=nums.end(); i++) {
        if (i->second==0) answer+=i->first; 
    }
    
    return answer;
}