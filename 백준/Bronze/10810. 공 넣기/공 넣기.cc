#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    int N, M, a, b, c;
    cin >> N >> M;

    int arr[N];

    for(int i = 0; i < N; i++)
        arr[i] = 0;

    for(int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;

        a--;
        b--;

        for(int j = a; j <= b; j++)
            arr[j] = c;
    }

    for(int i = 0; i < N; i++)
        cout << arr[i] << " ";

    return 0;
}