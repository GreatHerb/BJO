#include <iostream>

using namespace std;

int main()
{
    int H, W, N, M, x = 0, y= 0;
    cin >> H >> W >> N >> M;

    for(int i = 1; i <= H; i += N + 1)
        x += 1;
    
    for(int i = 1; i <= W; i += M + 1)
        y += 1;

    cout << x * y << endl;

    return 0;
}