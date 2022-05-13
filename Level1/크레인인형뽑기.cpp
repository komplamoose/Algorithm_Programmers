#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    stack<int> st;
    
    for (auto loop : moves) {
        int temp=-1;
        for (int i=0;i<board[0].size();i++){
            if (board[i][loop-1]!=0){
                temp=board[i][loop-1];
                board[i][loop-1]=0;
                break;
            }
        }
        if (temp==-1) continue;
        if (st.empty()){
            st.push(temp);
        }else if (temp==st.top()){
            st.pop();
            answer+=2;
        }else {
            st.push(temp);
        }
    }
    
    
    return answer;
}