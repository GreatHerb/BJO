#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int result = 1;
    string s;
    cin >> s;

    string p = s;
    reverse(p.begin(), p.end());
    
    int size = s.length();

    for(int i = 0; i < size; i++)
    {
        if(s[i] != p[i])
        {
            result = 0;
            break;
        }
    }

    cout << result << endl;
    return 0;
}