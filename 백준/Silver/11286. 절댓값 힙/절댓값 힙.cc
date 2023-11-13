#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

struct cmp
{
    bool operator()(int a, int b)
    {
        if(abs(a) == abs(b))
            return a > b;
        
        return abs(a) > abs(b);
    }
};


int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int N, X;
    priority_queue<int, vector<int>, cmp> pq;
    vector<int> v;

    cin >> N;

    for(int i = 0; i < N; i ++)
    {
        cin >> X;

        if(X == 0)
        {
            if(pq.empty())
                v.push_back(0);
            

            else    
            {
                v.push_back(pq.top());
                pq.pop();
            }
        }

        else
            pq.push(X);
    }

    for(auto a : v)
        cout << a << "\n";
}