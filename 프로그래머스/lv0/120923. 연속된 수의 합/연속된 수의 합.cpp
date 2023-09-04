#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    
    // 연속된 정수의 시작값을 계산
    int start = total / num - (num - 1) / 2;

    for (int i = 0; i < num; i++) 
        answer.push_back(start + i);
    
    return answer;
}