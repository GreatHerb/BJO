#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    string func;

    queue<int> q;
    vector<int> v;

    for(int i = 0; i < N; i ++)
    {
        cin >> func;
        
        if(func == "push")
        {
            int num;
            cin >> num;
            q.push(num);
        }

        else if(func == "pop")
        {
            if(q.empty())
                v.push_back(-1);
            else {
                v.push_back(q.front());
                q.pop();
            }
        }

        else if(func == "size")
            v.push_back(q.size());
        
        else if(func == "empty")
        {
            if(q.empty())
                v.push_back(1);
            else
                v.push_back(0);
        }

        else if(func == "front")
        {
            if(q.empty())
                v.push_back(-1);
            else
                v.push_back(q.front());
        }

        else // back
        {
            if(q.empty())
                v.push_back(-1);
            else
                v.push_back(q.back());
        }
    }

    for(const auto& a : v)
        cout << a << "\n";

    return 0;
}