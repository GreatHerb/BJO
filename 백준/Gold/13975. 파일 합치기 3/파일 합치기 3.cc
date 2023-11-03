#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int T, N, num;
    cin >> T;

    for(int k = 0; k < T; k ++)
    {
        cin >> N;

        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for(int i = 0; i < N; i ++)
        {
            cin >> num;
            pq.push(num);
        }

        long long result = 0;

        while(pq.size() != 1)
        {
            long long temp1 = pq.top();
            pq.pop();
            long long temp2 = pq.top();
            pq.pop();

            result += temp1 + temp2;

            long long sum = temp1 + temp2;
            pq.push(sum);
        }

        cout << result << "\n";
    }

    return 0;
}