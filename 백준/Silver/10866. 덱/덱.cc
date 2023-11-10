#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> dq;
    int N, num;
    cin >> N;

    for(int i = 0; i < N; i ++)
    {
        string s;
        cin >> s;

        if(s == "push_back")
        {
            cin >> num;
            dq.push_back(num);
        }

        else if(s == "push_front")
        {
            cin >> num;
            dq.push_front(num);
        }

        else if(s == "pop_front")
        {
            if(dq.empty())
                cout << -1 << "\n";
            else
            {
                int n = dq.front();
                cout << n << "\n";
                dq.pop_front();
            }
        }

        else if(s == "pop_back")
        {
            if(dq.empty())
                cout << -1 << "\n";
            else
            {
                int n = dq.back();
                cout << n << "\n";
                dq.pop_back();
            }
        }

        else if(s == "size")
            cout << dq.size() << "\n";
        
        else if(s == "empty")
        {
            if(dq.empty())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }

        else if(s == "front")
        {
            if(dq.empty())
                cout << -1 << "\n";
            else
                cout << dq.front() << "\n";
        }

        else
        {
            if(dq.empty())
                cout << -1 << "\n";
            else
                cout << dq.back() << "\n";
        }
    }
}