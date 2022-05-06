#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct stream{
    int id; // 고유번호
    int streamed; // 재생된 횟수
};

bool compare1(pair<int, int> a, pair<int,int> b) {
    if (a.second==b.second) return a.first < b.first;
    else return a.second > b.second;
}

bool compare2(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second; // 총실행횟수 기준 내림차순 정렬
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string, vector<pair<int,int>>> genresStreamList; // 장르, 고유번호, 재생횟수
    map<string, int> playedList; // 장르, 총 재생된 횟수
    
    for (int i=0; i<genres.size(); i++) {
        genresStreamList[genres[i]].push_back(make_pair(i, plays[i]));
        playedList[genres[i]]+=plays[i];
    }
    
    for (auto i=genresStreamList.begin(); i!=genresStreamList.end(); i++) {
        sort(i->second.begin(), i->second.end(), compare1);
    }
    
    vector<pair<string, int>> v(playedList.begin(), playedList.end());
    sort(v.begin(), v.end(), compare2); // 총 재생횟수 기준으로 정렬
    
    for (auto loop : v) {
        for (int i=0; i<2; i++) {
            answer.push_back(genresStreamList[loop.first][i].first);
            if (genresStreamList[loop.first].size()==1) break;
        }
    }
    
    return answer;
}