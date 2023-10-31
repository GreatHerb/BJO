#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int N, x;
    cin >> N;

    priority_queue<int, vector<int>, greater<>> q;
    vector<int> result;
    
    for(int i = 0; i < N; i ++)
    {
        cin >> x;

        if(x == 0)
        {
            if(q.empty())
                result.push_back(0);

            else
            {
                result.push_back(q.top());
                q.pop();
            }
        }

        else
            q.push(x);
    }

    for(auto a : result)
        cout << a << "\n";

    return 0;
}