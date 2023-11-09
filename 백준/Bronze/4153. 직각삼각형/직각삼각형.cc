#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    while(1)
    {
        long long a, b, c;
        vector<long long> t;

        cin >> a >> b >> c;

        if(a == 0 && b == 0 && c == 0)
            break;
        
        t.push_back(a);
        t.push_back(b);
        t.push_back(c);

        sort(t.begin(), t.end());

        if((t[0] * t[0]) + (t[1] * t[1]) == (t[2] * t[2]))
            cout << "right \n";
        else
            cout << "wrong \n";
    }
    
    return 0;
}