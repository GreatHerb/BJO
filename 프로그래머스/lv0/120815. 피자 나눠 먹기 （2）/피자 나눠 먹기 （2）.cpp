#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int pizza = 6;
    
    while(1) {
        if(pizza % n == 0) {
            answer = pizza / 6;
            break;
        }
        
        pizza += 6;
    }
    
    return answer;
}