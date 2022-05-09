#include <string>
#include <vector>
#include <algorithm>

/*
앞-뒤로 붙혀가면서, a+b와 b+a 중에 큰 값이 정하면 된다.
a+b가 b+a보다 크다면, 더 우위에 있다는 뜻이다.
*/

using namespace std;

bool compare(string a, string b){
    return a+b > b+a;
}

string solution(vector<int> n) {
    string answer = "";
    vector<string> numbers;
    for (auto loop : n) {
        numbers.push_back(to_string(loop));
    }
    
    sort(numbers.begin(),numbers.end(),compare);
    
    for (auto loop : numbers) {
        answer+=loop;
    }
    if (answer[0]=='0') return "0";
    return answer;
}