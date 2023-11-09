#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int N, M;
    long long num;

    cin >> N >> M;

    queue<long long> A;
    queue<long long> B;
    vector<long long> result;

    for(int i = 0; i < N; i ++)
    {
        cin >> num;
        A.push(num);
    }

    for(int i = 0; i < M; i ++)
    {
        cin >> num;
        B.push(num);
    }

    while (!A.empty() && !B.empty()) // 둘중 하나가 비면 종료
    {
        if(A.front() < B.front())
        {
            result.push_back(A.front());
            A.pop();
        }

        else
        {
            result.push_back(B.front());
            B.pop();
        }
    }

    int size;

    if(A.empty() && !B.empty()) // B가 남은경우
    {
        size = B.size();
        for(int i = 0; i < size; i ++)
        {
            result.push_back(B.front());
            B.pop();
        }
    }

    else
    {
        size = A.size();
        for(int i = 0; i < size; i ++)
        {
            result.push_back(A.front());
            A.pop();
        }
    }

    for(auto a : result)
        cout << a << " ";
    
    return 0;
}