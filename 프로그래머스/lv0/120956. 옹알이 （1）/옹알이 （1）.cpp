#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    for (int i = 0; i < babbling.size(); ++i) {
        // 1. 문자열에 들어갈 수 없는 것들이 있다면 건너뛰기
        if (babbling[i].find("ayaaya") != string::npos)
            continue;   

        else if (babbling[i].find("yeye") != string::npos)
            continue;

        else if (babbling[i].find("woowoo") != string::npos)
            continue;

        else if (babbling[i].find("mama") != string::npos)
            continue;

        else {
            // 2. babbling[i]에서 aya, ye, woo, ma를 찾았을 경우
            //    그 크기만큼 count에 더해줌
            int count = 0;
            if (babbling[i].find("aya") != -1)
                count += 3;

            if (babbling[i].find("ye") != -1)
                count += 2;

            if (babbling[i].find("woo") != -1)
                count += 3;
    
            if (babbling[i].find("ma") != -1)
                count += 2;

            // 3. count와 babbling[i]의 길이를 비교해서 같다면
            // answer에 + 1
            if (count == babbling[i].length())
                ++answer;
            
            // --> 
            // 같지 않다면 babbling[i]에 aya, ye, woo, ma를 제외한
            // 머쓱이가 발음할 수 없는 문자가 들어있었다는 뜻
        }
    }
    return answer;
}