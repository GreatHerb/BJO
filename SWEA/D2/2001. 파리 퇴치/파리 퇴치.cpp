#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T, N, M, count = 1;
    cin >> T;

    while(T--) {
        vector<vector<int>> v(16, vector<int>(16, 0));

        cin >> N >> M;
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                int num; cin >> num;
                v[i][j] = num + v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
            }
        }

        // MxM 최대 합 계산
        int best = 0; 
        for(int i = M; i <= N; i++) {
            for(int j = M; j <= N; j++) {
                int cur = v[i][j] - v[i - M][j] - v[i][j - M] + v[i - M][j - M];
                best = max(best, cur);
            }
        }

        cout << "#" << count++ << " " << best << endl;
    }
}