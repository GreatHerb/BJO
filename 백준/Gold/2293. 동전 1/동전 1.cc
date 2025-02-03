#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k, num;
    cin >> n >> k;

    vector<int> coins;
    vector<int> dp(10001);

    for(int i = 0; i < n; i++) {
        cin >> num;
        coins.push_back(num);
    }

    sort(coins.begin(), coins.end());
    dp[0] = 1;

    for(int i = 0; i < coins.size(); i++) {
        for(int j = coins[i]; j <= k; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    cout << dp[k] << endl;

    return 0;
}