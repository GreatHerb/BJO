#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> arr(N);

    // 입력 받기
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int heart_x = -1, heart_y = -1;

    // 심장 찾기
    for (int i = 1; i < N - 1 && heart_x == -1; i++) {
        for (int j = 1; j < N - 1; j++) {
            if (arr[i][j] == '*' &&
                arr[i - 1][j] == '*' && arr[i + 1][j] == '*' &&
                arr[i][j - 1] == '*' && arr[i][j + 1] == '*') {
                heart_x = i;
                heart_y = j;
                break;
            }
        }
    }

    // 길이 찾기
    int left_arm = 0, right_arm = 0, hip = 0, left_leg = 0, right_leg = 0;

    // 왼팔 길이
    int y = heart_y - 1;
    while (y >= 0 && arr[heart_x][y] == '*') {
        left_arm++;
        y--;
    }

    // 오른팔 길이
    y = heart_y + 1;
    while (y < N && arr[heart_x][y] == '*') {
        right_arm++;
        y++;
    }

    // 허리 길이
    int x = heart_x + 1;
    while (x < N && arr[x][heart_y] == '*') {
        hip++;
        x++;
    }

    // 왼다리 길이
    x = heart_x + hip + 1;
    while (x < N && arr[x][heart_y - 1] == '*') {
        left_leg++;
        x++;
    }

    // 오른다리 길이
    x = heart_x + hip + 1;
    while (x < N && arr[x][heart_y + 1] == '*') {
        right_leg++;
        x++;
    }

    cout << heart_x + 1 << " " << heart_y + 1 << endl;
    cout << left_arm << " " << right_arm << " " << hip << " " << left_leg << " " << right_leg << endl;

    return 0;
}