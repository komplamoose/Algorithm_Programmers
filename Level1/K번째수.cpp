#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (const auto& loop : commands) {
        int temp[101];
        int k=0;
        for (int i=loop[0]-1; i<=loop[1]-1; i++) {
            temp[k]=array[i];
            k++;
        }
        sort(temp, temp+(loop[1]-loop[0]+1));
        answer.push_back(temp[loop[2]-1]);
    }
    return answer;
}