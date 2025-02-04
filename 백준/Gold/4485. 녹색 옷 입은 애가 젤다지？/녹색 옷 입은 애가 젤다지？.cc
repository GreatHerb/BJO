#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void dijkstra(int N, vector<vector<int>>& cave) {
    vector<vector<int>> dist(N, vector<int>(N, INF)); // 최소 비용 저장
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    dist[0][0] = cave[0][0];
    pq.push({cave[0][0], {0, 0}});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (cost > dist[x][y]) continue; // 이미 최소 비용이면 패스

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                int newCost = cost + cave[nx][ny];

                if (newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    pq.push({newCost, {nx, ny}});
                }
            }
        }
    }

    cout << dist[N-1][N-1] << endl; 
}

int main() {
    int N, testCase = 1;

    while (true) {
        cin >> N;
        
        if (N == 0) 
            break;

        vector<vector<int>> cave(N, vector<int>(N));
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> cave[i][j];
            }
        }

        cout << "Problem " << testCase++ << ": ";
        dijkstra(N, cave);
    }

    return 0;
}
