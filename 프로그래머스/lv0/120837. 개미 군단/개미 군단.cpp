#include <string>
#include <vector>

using namespace std;

int solution(int hp) {
    int answer = 0;
    int numCommanders = hp / 5;   // 장군개미의 마리 수
    int remainingHp = hp % 5;     // 남은 체력

    int numSoldiers = remainingHp / 3;  // 병정개미의 마리 수
    remainingHp %= 3;  // 남은 체력 갱신
    
    answer = numCommanders + numSoldiers + remainingHp;
    return answer;
}