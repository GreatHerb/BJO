#include <iostream>

using namespace std;

int main()
{
    int dp[11] = {0, 1, 2, 4,};

    for(int i = 4; i < 11; i ++)
    {
        int sum = 0;

        for(int j = i - 3; j < i; j ++)
            sum += dp[j];
        
        dp[i] = sum;
    }

    int n, num;
    cin >> n;

    for(int i = 0; i < n; i ++)
    {
        cin >> num;
        cout << dp[num] << endl;
    }

    return 0;
}