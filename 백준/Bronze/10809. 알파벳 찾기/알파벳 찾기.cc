#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int arr[26];
    int size = s.length();

    // 배열 전처리
    for(int i = 0; i < 26; i++)
        arr[i] = -1;

    for(int i = 0; i < size; i++)
    {
        // 위치 탐색
        int target = s[i] - 97;

        // 갱신
        if(arr[target] == -1)
            arr[target] = i;
    }

    for(int i = 0; i < 26; i++)
        cout << arr[i] << " ";
}