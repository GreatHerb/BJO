#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char arr[5][16] = {0,}; 
    int max_length = 0; 

    // 각 줄의 문자열을 입력받음
    for(int i = 0; i < 5; i++) 
    {
        cin >> arr[i];
        int len = strlen(arr[i]); 

        if(len > max_length) // 가장 긴 문자열의 길이를 갱신
            max_length = len;
    }

    // 세로로 읽어서 출력
    for(int j = 0; j < max_length; j++) 
    {
        for(int i = 0; i < 5; i++) 
        {
            if(arr[i][j] != 0) 
                cout << arr[i][j];
        }
    }

    return 0;
}
