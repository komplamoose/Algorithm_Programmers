#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long calc(long long a, long long b, char ex)
{
    if (ex=='*') return a*b;
    else if (ex=='-') return a-b;
    else if (ex=='+') return a+b;
}

long long solution(string expression) {
    long long answer = 0;
    
    vector<long long> nums;
    vector<char> op;
    
    string temp="";
    for (auto loop : expression) {
        if (loop>='0'&&loop<='9') {
            temp+=loop;
        }else { // 수식일 경우
            op.push_back(loop);
            nums.push_back(stoll(temp));
            temp="";
        }
    }
    nums.push_back(stoll(temp)); // 마지막 숫자 저장
    // 파싱 완료
    
    vector<int> v{0, 1, 2};
    string s="+-*";
    
    do{
        vector<long long> temp_nums=nums;
        vector<char> temp_op=op;
        for (int i=0; i<3; i++) {
            for (int j=0; j<temp_op.size();) { // 우선순위 정해진 경우 그것 먼저 찾아서 계산
                if (s[v[i]]==temp_op[j]) {
                    long long result = calc(temp_nums[j], temp_nums[j+1], temp_op[j]);
                    temp_nums.erase(temp_nums.begin()+j);
                    temp_nums.erase(temp_nums.begin()+j); // 연속된 숫자 2개 뽑아낼것이니까 인덱스 그대로 유지
                    temp_nums.insert(temp_nums.begin()+j, result); // 숫자 2개 빼고 그 자리에 결과값 넣음
                    
                    temp_op.erase(temp_op.begin()+j); // 이 경우 j 삭제함으로서 한칸 줄었으니 j++ 안함    
                }else {
                    j++;
                }
            }
        }
        answer=max(answer, abs(temp_nums[0]));
    }while(next_permutation(v.begin(), v.end()));
    
    
    
    return answer;
}