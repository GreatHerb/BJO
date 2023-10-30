#include <iostream>

using namespace std;

int main()
{
    int arr[1001] = {0, 1, 2, };
    
    for(int i = 3; i < 1001; i ++)
        arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
    
    int n;
    cin >> n;

    cout << arr[n] << endl;
}