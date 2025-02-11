#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int bitmask = 0; // 비트마스크를 저장할 변수
    int M, num;
    string order;

    cin >> M;

    for (int i = 0; i < M; i++) {
        cin >> order;

        if (order == "add") {
            cin >> num;
            bitmask |= (1 << (num - 1)); // num번째 비트를 1로 설정
        }
        else if (order == "remove") {
            cin >> num;
            bitmask &= ~(1 << (num - 1)); // num번째 비트를 0으로 설정
        }
        else if (order == "check") {
            cin >> num;
            cout << ((bitmask & (1 << (num - 1))) ? "1\n" : "0\n");
        }
        else if (order == "toggle") {
            cin >> num;
            bitmask ^= (1 << (num - 1)); // num번째 비트를 반전
        }
        else if (order == "all") {
            bitmask = (1 << 20) - 1; // 20비트를 모두 1로 설정 (1~20 모두 포함)
        }
        else if (order == "empty") {
            bitmask = 0; // 모든 비트를 0으로 설정
        }
    }
    return 0;
}
