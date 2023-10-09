#include <iostream>

using namespace std;

int main()
{
    long N, num = 0, answer = 0;

    cin >> N;

    for(auto i = 1; ; i ++)
    {
        num += i;
        answer ++;

        if(num > N)
            break;
    }

    cout << answer - 1 << endl;

    return 0;
}