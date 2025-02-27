#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    long long N, total = 0;
    cin >> N;

    vector<long long> road(N - 1);
    vector<long long> price(N);

    for(long long i = 0; i < N - 1; i++) {
        cin >> road[i];
        total += road[i];
    }

    int min = -1;

    for(long long i = 0; i < N; i++) {
        cin >> price[i];

        if(min == -1)
            min = price[i];
        
        if(min > price[i] && i != N - 1)
            min = price[i];
    }
    
    long long ans = 0;
    for(long long i = 0; i < N - 1; i++) {
        if(price[i] != min) {
            ans += price[i] * road[i];
            total -= road[i];
        }

        else {
            ans += price[i] * total;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}