#include <iostream>
#include <string>
using namespace std;

int main()
{
    char arr[8][4] = {
        {'A', 'B', 'C'},
        {'D', 'E', 'F'},
        {'G', 'H', 'I'},
        {'J', 'K', 'L'},
        {'M', 'N', 'O'},
        {'P', 'Q', 'R', 'S'},
        {'T', 'U', 'V'},
        {'W', 'X', 'Y', 'Z'},
    };

    int result = 0;
    string s;

    cin >> s;

    for(int k = 0; k < s.length(); k ++)
    {
        for(int i = 0; i < 8; i ++)
        {
            for(int j = 0; j < 4; j++)
            {
                if(s[k] == arr[i][j])
                {
                    result += i + 3;
                    break;
                }
            }
        }
    }

    cout << result << endl;

    return 0;
}