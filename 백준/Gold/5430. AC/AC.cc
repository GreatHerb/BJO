#include <iostream>
#include <string>
#include <deque>
#include <sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n;
    string p, x;

    cin >> T;

    while (T--) 
    {
        cin >> p >> n >> x;
        bool error = false;
        bool reversed = false; // R 명령을 처리하기 위한 플래그
        deque<int> dq;

        // 숫자 추출 및 덱에 넣기
        for (int i = 0, num = 0; i < x.length(); i++) 
        {
            if(isdigit(x[i])) 
                num = num * 10 + (x[i] - '0');

            else if(x[i] == ',' || x[i] == ']') 
            {
                if(i > 1) 
                    dq.push_back(num); // 숫자를 덱에 넣음              
                num = 0;
            }
        }

        // 명령 처리 부분
        for (char order : p) 
        {
            if(order == 'R') 
                reversed = !reversed; // 덱의 뒤집힘 상태를 토글

            else if(order == 'D') 
            {
                if(dq.empty()) 
                {
                    cout << "error\n";
                    error = true;
                    break;
                }
                if(reversed) 
                    dq.pop_back(); // 뒤집혀 있으면 뒤에서 제거
                else
                    dq.pop_front(); // 뒤집혀 있지 않으면 앞에서 제거
            }
        }

        // 출력 부분
        if(!error) 
        {
            cout << "[";
            if(reversed) 
            {
                while (!dq.empty()) 
                {
                    cout << dq.back();
                    dq.pop_back();
                    if(!dq.empty()) 
                        cout << ",";
                }
            } 
            else 
            {
                while (!dq.empty()) 
                {
                    cout << dq.front();
                    dq.pop_front();
                    if(!dq.empty()) cout << ",";
                }
            }

            cout << "]\n";
        }
    }

    return 0;
}
