#include <vector>
#include <regex>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    
    sort(phone_book.begin(), phone_book.end());
    for (int i=0; i<phone_book.size()-1; i++) {
        string prefix="(";
        prefix+=phone_book[i];
        prefix+=")(.*)";
        regex re(prefix);
        if (regex_match(phone_book[i+1], re)==true) return false;
    }
    
    return true;
}