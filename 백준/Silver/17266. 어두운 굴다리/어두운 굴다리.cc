#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    vector<int> lamps(M);
    for (int i = 0; i < M; i++){
        cin >> lamps[i];
    }
    
    // 램프 위치 정렬
    sort(lamps.begin(), lamps.end());
    
    // 인접 램프 사이 최대 간격 계산
    int maxGap = 0;
    for (int i = 1; i < M; i++){
        maxGap = max(maxGap, lamps[i] - lamps[i - 1]);
    }
    
    // 필요한 최소 높이 계산
    // (maxGap+1)/2 는 올림 효과를 줌 (정수 나눗셈에서 올림 구현)
    int height = max({lamps[0], N - lamps[M - 1], (maxGap + 1) / 2});
    
    cout << height << "\n";
    return 0;
}