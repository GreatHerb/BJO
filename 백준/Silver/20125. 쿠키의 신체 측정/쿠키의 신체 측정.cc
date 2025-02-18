#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;

    string arr[N + 2][N + 2];
    string cookie;

    // 값 초기화
    for(int i = 0; i < N + 2; i++) {
        for(int j = 0; j < N + 2; j ++) {
            arr[i][j] = "X";
        }
    }

    // 입력 받기
    for(int i = 1; i <= N; i++) {
        cin >> cookie;

        for(int j = 0; j < cookie.length(); j++) 
            arr[i][j + 1] = cookie[j];
    }

    // 심장 찾기
    int heart_x, heart_y;

    for(int i = 1; i < N + 1; i++) {
        for(int j = 1; j < N + 1; j++) {
            if(arr[i][j] == "*" && arr[i - 1][j] == "*" && arr[i + 1][j] == "*" && arr[i][j - 1] == "*" && arr[i][j + 1] == "*") {
                heart_x = i;
                heart_y = j;
            }
        }
    }

    // 길이 찾기
    int left_arm = 0, right_arm = 0, hip = 0, left_leg = 0, right_leg = 0;
    
    for(int i = heart_y - 1; i > 0; i --) {
        if(arr[heart_x][i] == "*")
            left_arm ++;
    }

    for(int i = heart_y + 1; i < N + 1; i ++) {
        if(arr[heart_x][i] == "*")
            right_arm ++;
    }

    for(int i = heart_x; i < N + 1; i ++) {
        if(arr[i + 1][heart_y] == "*")
            hip ++;

        if(arr[i + 1][heart_y - 1] == "*")
            left_leg ++;

        if(arr[i + 1][heart_y + 1] == "*")
            right_leg ++;
    }

    cout << heart_x << " " << heart_y << endl;
    cout << left_arm << " " << right_arm << " " << hip << " " << left_leg << " " << right_leg << endl;

    return 0;
}