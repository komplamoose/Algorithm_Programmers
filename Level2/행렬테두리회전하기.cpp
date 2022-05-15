#include <string>
#include <vector>

using namespace std;

int mat[101][101];

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    int cnt=1;
    for (int i=0; i<rows; i++){
        for (int j=0; j<columns; j++) {
            mat[i][j]=cnt++;
        }
    }
    
    for (const auto& loop : queries) {
        int x1, y1, x2, y2;
        x1=loop[0]-1; y1=loop[1]-1; x2=loop[2]-1; y2=loop[3]-1;
        int temp = mat[x1][y1];
        int minValue=temp;
        for (int i=x1; i<x2; i++) { // 위로
            mat[i][y1]=mat[i+1][y1];
            minValue=min(minValue, mat[i][y1]);
        }
        for (int i=y1; i<y2; i++) { // 왼쪽으로
            mat[x2][i]=mat[x2][i+1];
            minValue=min(minValue, mat[x2][i]);
        }
        for (int i=x2; i>x1; i--){ // 아래로
            mat[i][y2]=mat[i-1][y2];
            minValue=min(minValue, mat[i][y2]);
        }
        for (int i=y2; i>y1+1; i--){ // 오른쪽으로, (x1, y1+1)은 x1, y1 그대로 옮겨주면 되니까 안해도 됨.
            mat[x1][i]=mat[x1][i-1];
            minValue=min(minValue, mat[x1][i]);
        }
        
        mat[x1][y1+1]=temp;
        
        answer.push_back(minValue);
    }
    
    
    return answer;
}