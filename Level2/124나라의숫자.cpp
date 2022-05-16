#include <string>
#include <vector>

using namespace std;


string solution(int n) {
    string answer = "";
    // 3으로 나누었을때 0으로 떨어지면 4, 1로 떨어지면 1, 2로 떨어지면 4
    while (n>0){
        int r=n%3;
        answer = "412"[r] + answer;
        n=(n-1)/3; // n-1 해주는 이유, 3으로 떨어지는 경우, 그대로 3분할하면 바깥 범위에 걸침. 
        // 3분할 하면 다음 자릿수(맨뒤에서부터 채워짐) 정하러 갈 수 있음
    }
    
    return answer;
}