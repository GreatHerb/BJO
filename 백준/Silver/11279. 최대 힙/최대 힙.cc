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

    vector<int> result;
    priority_queue<int> pq;

    for(int i = 0; i < N; i ++)
    {
        cin >> num;
        
        if(num == 0)
        {
            if(pq.empty())
                result.push_back(0);
            
            else
            {
                result.push_back(pq.top());
                pq.pop();
            }
        }

        else
            pq.push(num);
    }

    for(auto a : result)
        cout << a << "\n";
}