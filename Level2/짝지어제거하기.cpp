#include <stack>
#include <string>

using namespace std;

int solution(string s)
{   
    stack<char> st;
    
    for (auto loop : s) {
        if (st.empty()) st.push(loop);
        else {
            if (st.top()==loop) {
                st.pop();
            }else {
                st.push(loop);
            }
        }
    }
    
    if (st.empty()) return 1;
    else return 0;
}