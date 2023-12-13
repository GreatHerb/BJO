#include <iostream>

using namespace std;

int main()
{
    int N, v, count = 0;
    cin >> N;

    int arr[N];

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    cin >> v;
    
    for(int i = 0; i < N; i++)
    {
        if(arr[i] == v)
            count ++;
    }

    cout << count << endl;

    return 0;
}