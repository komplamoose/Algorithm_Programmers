#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    for (int i=0; i<a.size(); i++) {
        answer += a[i]*b[i];
    }
    return answer;
}

// <numeric> 의 inner_product() 함수 사용시 내적 구할 수 있음.