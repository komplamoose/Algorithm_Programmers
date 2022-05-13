#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<pair<int, int>> v;
    
    int one[5]={1, 2, 3, 4, 5};
    int one_score=0;
    int two[8]={2, 1, 2, 3, 2, 4, 2, 5};
    int two_score=0;
    int three[10]={3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int three_score=0;
    
    int i=0, j=0, k=0;
    for (auto loop : answers) {
        if (one[i++]==loop) one_score++;
        if(i==5) i=0;
        if (two[j++]==loop) two_score++;
        if(j==8) j=0;
        if (three[k++]==loop) three_score++;
        if(k==10) k=0;
    }
    v.push_back(make_pair(one_score,1));
    v.push_back(make_pair(two_score,2));
    v.push_back(make_pair(three_score,3));
    stable_sort(v.begin(), v.end(), cmp);
    
    answer.push_back(v[0].second);
    for (int i=1; i<v.size(); i++){
        if (v[i].first==v[0].first) answer.push_back(v[i].second);
    }
    
    return answer;
}