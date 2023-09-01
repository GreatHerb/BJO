#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
    int answer = 0;
    int coupons = 0;

    while (chicken > 0) {
        answer += chicken;
        coupons += chicken;
        chicken = coupons / 10;
        coupons %= 10;
    }

    answer /= 10;
    
    return answer;
}