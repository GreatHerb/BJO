#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Country {  
    int country_code;
    int gold, silver, bronze;
    int rank;
};

// 비교 함수 (금 -> 은 -> 동 내림차순 정렬)
bool cmp(const Country &a, const Country &b) {
    if (a.gold != b.gold) 
        return a.gold > b.gold;
    if (a.silver != b.silver) 
        return a.silver > b.silver;

    return a.bronze > b.bronze;
}

int main() {   
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K; // N: 국가 수, K: 등수를 알고 싶은 국가
    cin >> N >> K;

    vector<Country> v(N);

    // 입력 처리
    for (int i = 0; i < N; i++) {
        cin >> v[i].country_code >> v[i].gold >> v[i].silver >> v[i].bronze;
    }
    
    // 금, 은, 동 순으로 내림차순 정렬
    sort(v.begin(), v.end(), cmp);

    // 등수 계산
    v[0].rank = 1; // 첫 번째 국가 등수는 1
    for (int i = 1; i < N; i++) {
        if (v[i].gold == v[i - 1].gold && v[i].silver == v[i - 1].silver && v[i].bronze == v[i - 1].bronze) {
            v[i].rank = v[i - 1].rank; // 같은 메달 수면 같은 등수
        } 
        
        else {
            v[i].rank = i + 1; // 새로운 등수 할당
        }
    }

    // 국가 K의 등수 찾기
    for (int i = 0; i < N; i++) {
        if (v[i].country_code == K) {
            cout << v[i].rank << '\n';
            break;
        }
    }

    return 0;
}