#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Country
{  
    int conrty_code;
    int gold;
    int silver;
    int bronze;
    int rank = 1;
};

bool cmp(const Country & a, const Country & b) 
{
    if(a.gold > b.gold)
        return true;
    
    else if(a.gold == b.gold)
    {
        if(a.silver > b.silver)
            return true;
        
        else if(a.silver == b.silver)
        {
            if(a.bronze > b.bronze)
                return true;
        }
    }

    return false;
}


int main()
{   
    int N, K; // N : 국가의 수, K : 등수를 알고 싶은 국가
    cin >> N >> K;

    vector<Country> v(N);

    // 입력 처리
    for(int i = 0; i < N; i++) 
        cin >> v[i].conrty_code >> v[i].gold >> v[i].silver >> v[i].bronze;
    
    sort(v.begin(), v.end(), cmp); // 금 -> 은 -> 동 순서로 내림차순 정렬

    for(int i = 1; i < N; i++) {
        if(v[i - 1].gold == v[i].gold) { // 1. 금의 개수가 같은 경우
            if(v[i - 1].silver == v[i].silver) { // 2. 금의 개수가 같고 은의 개수도 같은 경우
                if(v[i - 1].bronze == v[i].bronze) { // 3. 금, 은, 동의 개수가 모두 같은 경우
                    v[i].rank = v[i - 1].rank; // 등수 유지
                    continue;
                }
            }
        }

        v[i].rank = v[i - 1].rank + 1;
    }

    for(int i = 0; i < v.size(); i++) {
        if(v[i].conrty_code == K) {
            cout << v[i].rank << endl;
            break;
        }
    }

    return 0;
}