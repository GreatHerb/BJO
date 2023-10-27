#include <iostream>
#include <vector>
using namespace std;

int arr[21][21][21];

int W(int a, int b, int c)
{
    if(a <= 0 || b <= 0 || c <= 0)
        return 1;
    
    if(a > 20 || b > 20 || c > 20)
        return W(20, 20, 20);
    
    if(arr[a][b][c])
        return arr[a][b][c];
    
    if(a < b && b < c)
    {
        arr[a][b][c] = W(a, b, c - 1) + W(a, b - 1, c - 1) - W(a, b - 1, c);
        return arr[a][b][c];
    }
    else
    {
        arr[a][b][c] = W(a - 1, b, c) + W(a - 1, b - 1, c) + W(a - 1, b, c - 1) - W(a - 1, b - 1, c - 1);
        return arr[a][b][c];
    }
}

int main()
{
    int result, a, b, c;

    while(1)
    {
        cin >> a >> b >> c;

        if(a == -1 && b == -1 && c == -1)
            break;

        result = W(a, b, c);
        cout << "w(" << a << ", " << b << ", " << c << ") = " << result << endl;
    }

    return 0;
}