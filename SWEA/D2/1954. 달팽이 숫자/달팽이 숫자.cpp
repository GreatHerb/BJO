#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> makeSpiral(int n) {
    vector<vector<int>> a(n, vector<int>(n, 0));

    // 시계 방향: 오른쪽, 아래, 왼쪽, 위
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};
    
    int x = 0, y = 0, dir = 0;

    for(int i = 1; i <= n * n; i++) {
        a[x][y] = i;
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx < 0 || nx >= n || ny < 0 || ny >= n || a[nx][ny] != 0) {
            dir = (dir + 1) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }

        x = nx;
        y = ny;
    }

    return a;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, count = 1;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        if (N <= 0) 
            return 0;

        auto snail = makeSpiral(N);

        cout << "#" << count++ << endl;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << snail[i][j] << (j + 1 == N ? '\n' : ' ');
            }
        }
    }
    return 0;
}