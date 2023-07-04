#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    int a = n;
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    
    for( ; ;n /= 10) {
        if(n < 10)
            break;
        answer += n % 10;
    }

    answer += n;
    cout << answer << endl;
    return answer;
}