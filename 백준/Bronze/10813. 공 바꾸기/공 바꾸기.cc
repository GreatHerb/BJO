#include <iostream>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    int arr[N];

    for(int i = 0; i < N; i++)
        arr[i] = i + 1;
    
    for(int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        swap(arr[a], arr[b]);
    }

    for(auto a : arr)
        cout << a << " ";
        
    return 0;
}