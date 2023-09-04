#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> arr) {
    int answer = 1;
    int n = arr.size();
    
    for(int i = 0; i < n; i ++) {
        if(answer == 0)
            break;
        
        for(int j = 0; j < n; j ++) {
            if(arr[i][j] != arr[j][i]) {
                answer = 0;
                break;
            }
        }
    }
    
    return answer;
}