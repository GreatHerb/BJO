#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) {
    int answer = 0;
    int n = A.size();
    
    for (int i = 0; i < n; i ++) {
        if (A == B) 
            return i; // A와 B가 같아지면 밀어야 하는 최소 횟수는 i      
        
        // A를 한 칸 오른쪽으로 밀기
        char last_char = A[n - 1];
        for (int j = n - 1; j > 0; j --) 
            A[j] = A[j - 1];
        
        A[0] = last_char;
    }
    
    return -1;
}