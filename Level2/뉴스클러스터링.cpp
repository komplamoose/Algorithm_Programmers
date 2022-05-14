#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    
    vector<string> v1;
    vector<string> v2;
    
    for (int i=0; i<str1.size()-1; i++) {
        if (isalpha(str1[i])==0||isalpha(str1[i+1])==0) continue;
        string temp;
        temp.push_back(tolower(str1[i]));
        temp.push_back(tolower(str1[i+1]));
        v1.push_back(temp);
    }
    for (int i=0; i<str2.size()-1; i++) {
        if (isalpha(str2[i])==0||isalpha(str2[i+1])==0) continue;
        string temp;
        temp.push_back(tolower(str2[i]));
        temp.push_back(tolower(str2[i+1]));
        v2.push_back(temp);
    }
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    vector<string> uni;
    vector<string> inter;
    set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(uni));
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(inter));
    
    if (uni.size()==0&&inter.size()==0){
        answer=1*65536;
    }else{
        answer=((double)inter.size()/uni.size())*65536;
    }
    
    
    return answer;
}