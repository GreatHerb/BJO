#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n));
    
    int num = 1;
    int row_start = 0, row_end = n - 1, col_start = 0, col_end = n - 1;
    
    
    while (num <= n * n) {
        for (int col = col_start; col <= col_end; col++) 
            answer[row_start][col] = num++;
        
        row_start++;

        for (int row = row_start; row <= row_end; row++) 
            answer[row][col_end] = num++;
    
        col_end--;


        for (int col = col_end; col >= col_start; col--) 
            answer[row_end][col] = num++;
        
        row_end--;

        for (int row = row_end; row >= row_start; row--) 
            answer[row][col_start] = num++;
        
        col_start++;
    }
    return answer;
}