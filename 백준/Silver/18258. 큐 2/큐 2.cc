#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int N;
    cin >> N;

    queue<int> q;

    for(int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        if(s == "push")
        {
            int num;
            cin >> num;

            q.push(num);
        }

        else if(s == "pop")
        {
            if(q.empty())
            {
                cout << -1 << "\n";
                continue;
            }

            int num = q.front();
            cout << num << "\n";

            q.pop();
        }

        else if(s == "size")
            cout << q.size() << "\n";
        

        else if(s == "empty")
        {
            if(q.empty())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }

        else if(s == "front")
        {
            if(q.empty())
            {
                cout << -1 << "\n";
                continue;
            }

            cout << q.front() << "\n";
        }

        else
        {
            if(q.empty())
            {
                cout << -1 << "\n";
                continue;
            }

            cout << q.back() << "\n";
        }   
    }

    return 0;
}