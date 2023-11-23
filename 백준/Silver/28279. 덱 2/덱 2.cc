#include <iostream>
#include <deque>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    deque<int> dq;
    int N, order, num;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> order;

        if(order == 1)
        {
            cin >> num;
            dq.push_front(num);
        }

        else if(order == 2)
        {
            cin >> num;
            dq.push_back(num);
        }

        else if(order == 3)
        {
            if(dq.empty())
                cout << "-1 \n";
            else
            {
                int temp = dq.front();
                dq.pop_front();
                cout << temp << "\n";
            }
        }

        else if(order == 4)
        {
            if(dq.empty())
                cout << "-1 \n";
            else
            {
                int temp = dq.back();
                dq.pop_back();
                cout << temp << "\n";
            }
        }

        else if(order == 5)
            cout << dq.size() << "\n";
        
        else if(order == 6)
        {
            if(dq.empty())
                cout << "1 \n";  
            else
                cout << "0 \n";
        }

        else if(order == 7)
        {
            if(dq.empty())
                cout << "-1 \n";          
            else
                cout << dq.front() << "\n";
        }

        else
        {
            if(dq.empty())
                cout << "-1 \n";
            else
                cout << dq.back() << "\n";
        }
    }

    return 0;
}