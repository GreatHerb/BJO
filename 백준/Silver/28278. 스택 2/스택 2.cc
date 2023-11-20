#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    int N, order, num;
    cin >> N;

    stack<int> s;

    for(int i = 0; i < N; i++)
    {
        cin >> order;
        if(order == 1)
        {
            cin >> num;
            s.push(num);
        }

        else if(order == 2)
        {
            if(s.empty())
                cout << "-1" << "\n";
            
            else
            {
                int temp = s.top();
                s.pop();
                cout << temp << "\n";
            }
        }

        else if(order == 3)
            cout << s.size() << "\n";
        
        else if(order == 4)
        {
            if(s.empty())
                cout << "1" << "\n";
            else
                cout << "0" << "\n";
        }

        else
        {
            if(s.empty())
                cout << "-1" << "\n";
            else
                cout << s.top() << "\n"; 
        }

    }
    return 0;
}