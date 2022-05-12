#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i=0; i<arr1.size(); i++) {
        int pw= arr1[i]|arr2[i];
        string decode="";
        for (int j=n-1; j>=0; --j) {
            int result = pw >> j & 1;
            if (result==1) decode+="#";
            else decode+=" ";
        }
        answer.push_back(decode);
    }
    return answer;
}

/*
비트연산자 활용.
*/