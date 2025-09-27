#include<string>
#include <iostream>
#include <vector>
using namespace std;

bool solution(string s)
{
    int answer = 0;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(')
            answer ++;
        else {
            if(answer == 0)
                return false;
            answer --;
        }
    }
    
    return answer == 0;
}