#include <iostream>
#include <string>
#include <vector>

using namespace  std;

int main()
{
    while (true) {
        string s;
        cin >> s;

        if(s == "end") 
            break;
        
        /*  <높은 품질 비밀번호의 조건>
            1. 모음 a, e, i, o, u 하나를 반드시 포함
            2. 모음, 자음이 3개 연속으로 오면 안 됨
            3. 같은 글자가 연속으로 두 번 오면 안되나 "ee, oo"만 허용
        */

        string vowel = "aeiou"; // 모음
        bool flag = false;

        // 1. 모음 포함 하는지 체크
        for(int i = 0; i < 5; i++) {
            if(s.find(vowel[i]) != string::npos) { // 포함 하는 경우
                flag = true;
                break;
            }
        }

        if(!flag) { // 1번 조건 탈락
            cout << "<" << s << "> is not acceptable." << endl;
            continue;
        }

        if(s.length() == 1) { // 1글자인 경우 : a, e, i, o ,u
            cout << "<" << s << "> is acceptable." << endl;
            continue;
        }

        // 2. 모음, 자음이 3개 연속으로 오는지 체크 : 예외) ab? aa? ec?
        if(s.length() >= 3) {
            flag = true; // flag 초기화

            for(int i = 1; i < s.length() - 1; i++) {
                // 2-1. 모음이 3개 연속으로 오는 경우
                if(vowel.find(s[i - 1]) != string::npos && vowel.find(s[i]) != string::npos && vowel.find(s[i + 1]) != string::npos) {
                    flag = false;
                    break;
                }

                // 2-2. 자음이 3개 연속으로 오는 경우
                if(vowel.find(s[i - 1]) == string::npos && vowel.find(s[i]) == string::npos && vowel.find(s[i + 1]) == string::npos) {
                    flag = false;
                    break;
                }           
                
            }

            if(!flag) { // 2번 조건 탈락
                cout << "<" << s << "> is not acceptable." << endl;
                continue;
            }
        }

        // 3. 같은 글자가 연속으로 두 번 오면 안되나 "ee, oo"만 허용 : 예외) ab? aa? ec?
        flag = true; // flag 초기화
        for(int i = 1; i < s.length(); i++) {
            if(s[i - 1] == s[i]) { // 같은 글자 연속으로 오는 경우
                if(s[i - 1] == 'e' && s[i] == 'e')
                    continue;

                if(s[i - 1] == 'o' && s[i] == 'o')
                    continue;

                flag = false;
                break;
            }
        }

        if(!flag) { // 3번 조건 탈락
            cout << "<" << s << "> is not acceptable." << endl;
            continue;
        }

        if(flag) { // 모든 조건 합격
            cout << "<" << s << "> is acceptable." << endl;
            continue;
        }
    }
    

    return 0;
}