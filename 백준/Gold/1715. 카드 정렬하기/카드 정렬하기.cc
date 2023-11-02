#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int N, num;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < N; i ++)
    {
        cin >> num;
        pq.push(num);
    }

    int result = 0;

    while(pq.size() != 1)
    {
        int temp1 = pq.top();
        pq.pop();
        int temp2 = pq.top();
        pq.pop();

        result += temp1 + temp2;

        int sum = temp1 + temp2;
        pq.push(sum);
    }

    cout << result << endl;
    return 0;
}