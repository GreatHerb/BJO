#include <iostream>

using namespace std;

int main()
{
    int X, n, a, b, sum = 0;
    string answer = "";
    cin >> X >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        sum += (a * b);
    }

    if(X == sum)
        answer = "Yes";
    else
        answer = "No";

    cout << answer << endl;
    
    return 0;
}