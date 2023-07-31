#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    while(true) {
        if(n == 1) {
            answer.push_back(1);
            break;
        }
        
        answer.push_back(n);
        
        if(n % 2 == 0) // 짝수
            n /= 2;
        
        else // 홀수
            n = (3 * n) + 1;
    }
    
    return answer;
}