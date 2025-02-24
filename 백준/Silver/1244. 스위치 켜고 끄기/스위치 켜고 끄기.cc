#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> switches(n + 1);  // 1번부터 사용하기 위해 n+1 크기 벡터 생성
    for (int i = 1; i <= n; i++) {
        cin >> switches[i];
    }
    
    int student_count;
    cin >> student_count;
    while (student_count--) {
        int gender, num;
        cin >> gender >> num;
        if (gender == 1) {  // 남학생의 경우: num의 배수 위치 토글
            for (int i = num; i <= n; i += num) {
                switches[i] = switches[i] ? 0 : 1;
            }
        } else {  // 여학생의 경우: 중앙 스위치부터 좌우 대칭 검사
            // 중앙 스위치 토글
            switches[num] = switches[num] ? 0 : 1;
            int offset = 1;
            // 범위 내에서 좌우 대칭이면 토글
            while (num - offset >= 1 && num + offset <= n &&
                   switches[num - offset] == switches[num + offset]) {
                switches[num - offset] = switches[num - offset] ? 0 : 1;
                switches[num + offset] = switches[num + offset] ? 0 : 1;
                offset++;
            }
        }
    }
    
    // 20개씩 출력
    for (int i = 1; i <= n; i++) {
        cout << switches[i] << " ";
        if (i % 20 == 0)
            cout << "\n";
    }
    return 0;
}