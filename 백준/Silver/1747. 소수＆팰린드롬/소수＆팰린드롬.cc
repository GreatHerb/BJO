#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    const int MAXN = 2000000;
    vector<bool> is_prime(MAXN + 1, true);
    is_prime[0] = is_prime[1] = false;

    // 소수 추가하기
    for(int i = 2; i * i <= MAXN; i++) {
        if(is_prime[i]) {
            for(int j = i * i; j <= MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }

    // 팰린드롬 만족하는 수 찾기
    vector<int> v;
    for(int i = 2; i <= MAXN; i++) {
        if(is_prime[i]) {
            string s1 = to_string(i);
            string s2 = s1;

            reverse(s1.begin(), s1.end());

            if(s1 == s2)
                v.push_back(i);
        }
    }
    
    // 입력 받기
    int N;
    cin >> N;

    for(int i = 0; i < v.size(); i++) {
        if(v[i] >= N) {
            cout << v[i] << endl;
            break;
        }
    }

    return 0;
}
