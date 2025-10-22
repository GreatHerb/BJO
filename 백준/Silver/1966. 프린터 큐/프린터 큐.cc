#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int T, N, M;
    cin >> T;

    while(T--) {
        cin >> N >> M;
        queue<pair<int,bool>> q;
        vector<int> v;
        
        int max = -1, count = 1;

        // 입력받기, 최대값 찾기
        for(int i = 0; i < N; i++) {
            int num;
            cin >> num;
            v.push_back(num);

            if(max < num)
                max = num;

            if(i == M)
                q.push(make_pair(num, true));
            
            else
                q.push(make_pair(num, false));
        }

        sort(v.begin(), v.end());

        while(true) {
            // 중요도가 가장 큰 값이 찾는 값이고 가장 앞에 있음
            if(q.front().first == max && q.front().second == true) {
                break;
            }
            
            // 중요도가 가장 큰 값이 가장 앞에 있고 찾는 값이 아님
            if(q.front().first == max && q.front().second == false) {
                q.pop();
                count ++;

                // 가장 큰 값 초기화
                v.pop_back();
                max = v.back();
            }

            // 중요도가 크지 않음. 찾는 값이 아님
            if(q.front().first < max) {
                int temp1; bool temp2;
                temp1 = q.front().first;
                temp2 = q.front().second;
                q.pop();
                q.push(make_pair(temp1, temp2));
            }
        }

        cout << count << endl;

    }

    return 0;
}